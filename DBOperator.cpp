#include <util/tc_common.h>
#include "DBOperator.h"
#include "LogComm.h"
#include "Log2DBServer.h"

//
using namespace wbl;

/**
 *
*/
CDBOperator::CDBOperator()
{

}

/**
 *
*/
CDBOperator::~CDBOperator()
{

}

//初始化
int CDBOperator::init(const TLogConfig &tLogConfig)
{
    FUNC_ENTRY("");

    int iRet = 0;

    try
    {
        m_tLogConfig = tLogConfig;
        m_mysqlObj.init(m_tLogConfig.dbConfig.strDBHost, m_tLogConfig.dbConfig.strDBUser, m_tLogConfig.dbConfig.strDBPwd,
                        m_tLogConfig.dbConfig.strDBName, m_tLogConfig.dbConfig.strDBCharSet, m_tLogConfig.dbConfig.iDBPort);
    }
    catch (exception &e)
    {
        iRet = -1;
        ROLLLOG_ERROR << "Catch exception: " << e.what() << endl;
    }
    catch (...)
    {
        iRet = -2;
        ROLLLOG_ERROR << "Catch unknown exception" << endl;
    }

    FUNC_EXIT("", iRet);

    return iRet;
}


//日志入库
int CDBOperator::log(int id, const std::string &buffer)
{
    FUNC_ENTRY("");

    int iRet = 0;

#if 0
    TLogConfig tLogConfig;
    iRet = g_app.getOuterFactoryPtr()->getLogConfigByID(id, tLogConfig);
    if (iRet != 0)
    {
        //找不到配置，直接返回
        return -1;
    }
#endif

    vector<string> vecItem;
    split_string(buffer, "[ \t]*\\|[ \t]*", vecItem);

    //if (tLogConfig.vecLogConfigItems.size() != vecItem.size())
    if (m_tLogConfig.vecLogConfigItems.size() > vecItem.size())
    {
        return -2;
    }

    try
    {
        map<string, pair<TC_Mysql::FT, string> > m;
        for (size_t i = 0; i < m_tLogConfig.vecLogConfigItems.size(); i++)
        {
            if (m_tLogConfig.vecLogConfigItems[i].type == TC_Mysql::DB_INT)
            {
                if (vecItem[i].length() == 0)
                {
                    m[m_tLogConfig.vecLogConfigItems[i].field] = make_pair(TC_Mysql::DB_INT, "0");
                }
                else
                {
                    m[m_tLogConfig.vecLogConfigItems[i].field] = make_pair(TC_Mysql::DB_INT, vecItem[i]);
                }
            }
            else if (m_tLogConfig.vecLogConfigItems[i].type == TC_Mysql::DB_STR)
            {
                if (vecItem[i].length() == 0)
                {
                    m[m_tLogConfig.vecLogConfigItems[i].field] = make_pair(TC_Mysql::DB_STR, "");
                }
                else
                {
                    m[m_tLogConfig.vecLogConfigItems[i].field] = make_pair(TC_Mysql::DB_STR, vecItem[i]);
                }
            }
            else
            {
                continue;
            }
        }

        //m["ver_id"] = make_pair(TC_Mysql::DB_INT, "2334");
        //m["kKey"] = make_pair(TC_Mysql::DB_STR, "abcttt");
        //m["kValue"] = make_pair(TC_Mysql::DB_STR, "abcapbbp");
        //m["modify_time"] = make_pair(TC_Mysql::DB_STR, "2015-04-06 09:44:00");

        size_t size = 0;
        //size = m_mysqlObj.insertRecord("t_hall_key_value_des", m);
        size = m_mysqlObj.insertRecord(m_tLogConfig.tablename, m);
        if (size != 1)
        {
            return -3;
        }
    }
    catch (TC_Mysql_Exception &e)
    {
        ROLLLOG_ERROR << "Catch exception: " << e.what() << endl;
        return -4;
    }
    catch (...)
    {
        ROLLLOG_ERROR << "Catch unknown exception" << endl;
        return -5;
    }

    FUNC_EXIT("", iRet);
    return iRet;
}

//日志入库
int CDBOperator::log(const vector<string> &vecItem)
{
    FUNC_ENTRY("");
    int iRet = 0;

    if (m_tLogConfig.vecLogConfigItems.size() > vecItem.size())
    {
        return -1;
    }

    try
    {
        map<string, pair<TC_Mysql::FT, string> > m;
        for (size_t i = 0; i < m_tLogConfig.vecLogConfigItems.size(); i++)
        {
            if (m_tLogConfig.vecLogConfigItems[i].type == TC_Mysql::DB_INT)
            {
                if (vecItem[i].length() == 0)
                {
                    m[m_tLogConfig.vecLogConfigItems[i].field] = make_pair(TC_Mysql::DB_INT, "0");
                }
                else
                {
                    m[m_tLogConfig.vecLogConfigItems[i].field] = make_pair(TC_Mysql::DB_INT, vecItem[i]);
                }
            }
            else if (m_tLogConfig.vecLogConfigItems[i].type == TC_Mysql::DB_STR)
            {
                if (vecItem[i].length() == 0)
                {
                    m[m_tLogConfig.vecLogConfigItems[i].field] = make_pair(TC_Mysql::DB_STR, "");
                }
                else
                {
                    m[m_tLogConfig.vecLogConfigItems[i].field] = make_pair(TC_Mysql::DB_STR, vecItem[i]);
                }
            }
            else
            {
                continue;
            }
        }

        size_t size = 0;
        //size = m_mysqlObj.insertRecord(m_tLogConfig.tablename, m);
        size = m_mysqlObj.replaceRecord(m_tLogConfig.tablename, m);
        //if (size != 1)
        if (size < 1)
        {
            return -2;
        }
    }
    catch (TC_Mysql_Exception &e)
    {
        ROLLLOG_ERROR << "Catch exception: " << e.what() << endl;
        iRet = -3;
    }
    catch (...)
    {

        ROLLLOG_ERROR << "Catch unknown exception" << endl;
        iRet = -4;
    }

    FUNC_EXIT("", iRet);
    return iRet;
}

//日志入库
int CDBOperator::log(const vector<vector<string> > &vecItem)
{
    FUNC_ENTRY("");
    int iRet = 0;

    if (vecItem.size() == 0)
    {
        return -1;
    }

    for (auto it = vecItem.begin(); it != vecItem.end(); ++it)
    {
        iRet = log(*it);
        if (iRet != 0)
        {

        }
    }

    FUNC_EXIT("", iRet);
    return iRet;

}

//日志查询
int CDBOperator::queryDB(const string &szCondition, vector<vector<string> > &vecItem)
{
    FUNC_ENTRY("");

    int iRet = 0;

    try
    {
        int index = 0;
        string strSql = "select ";
        for (size_t i = 0; i < m_tLogConfig.vecLogConfigItems.size(); i++)
        {
            strSql += m_tLogConfig.vecLogConfigItems[i].field;
            index++;
            if ((size_t)index != m_tLogConfig.vecLogConfigItems.size())
            {
                strSql += ",";
            }
        }

        strSql += " from " + m_tLogConfig.tablename;
        if (szCondition.length() > 0)
        {
            strSql += " " + szCondition;
        }

        ROLLLOG_DEBUG << "strSql: " << strSql << endl;

        TC_Mysql::MysqlData res = m_mysqlObj.queryRecord(strSql);
        ROLLLOG_DEBUG << "Execute SQL: [" << strSql << "], return " << res.size() << " records" << endl;
        if (res.size() <= 0)
        {
            ROLLLOG_WARN << "Table t_hall_version_update_des no data!" << endl;
            return 0;
        }

        vector<string> vecData;
        for (size_t i = 0; i < res.size(); ++i )
        {
            vecData.clear();
            for (size_t j = 0; j < m_tLogConfig.vecLogConfigItems.size(); j++)
            {
                vecData.push_back(res[i][m_tLogConfig.vecLogConfigItems[j].field]);
            }

            vecItem.push_back(vecData);
        }
    }
    catch (TC_Mysql_Exception &e)
    {
        ROLLLOG_ERROR << "Catch exception: " << e.what() << endl;
        iRet = -3;
    }
    catch (...)
    {
        ROLLLOG_ERROR << "Catch unknown exception" << endl;
        iRet = -4;
    }

    FUNC_EXIT("", iRet);
    return iRet;
}


