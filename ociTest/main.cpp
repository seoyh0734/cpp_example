/* Standard Library */
#include <iostream>

/* oci headers */
#include "oci.h"

int select()
int insert()
int main(int argc, char* argv[])
{
  return 0;
}
{
    OCIEnv *env = NULL;
    OCIError *err = NULL;
    OCIServier *srv = NULL;
    OCISvcCtx *svc = NULL;
    OCISession *ses = NULL;

    text username[30] = "damo";
    text password[30] = "damo";
    text dbname[30] = "orclpdb1";

    sword ret;

    ret = OCIEnvCreate(&env, OCI_DEFAULT, 0, 0, 0, 0, 0, 0);
    if (ret != OCI_SUCCESS)
    {
        std::cout << "Failed to OCIEnvCreate" << std::endl;
        goto clean;
    }

    OCIHandleAlloc(env, (dvoid**)&err, OCI_HTYPE_ERROR, 0, 0);
    OCIHandleAlloc(env, (dvoid**)&srv, OCI_HTYPE_SERVER, 0, 0);
    OCIHandleAlloc(env, (dvoid**)&svc, OCI_HTYPE_SVCCTX, 0, 0);
    OCIHandleAlloc(env, (dvoid**)&ses, OCI_HTYPE_SESSION, 0, 0);

    ret = OCIServerAttach(srv, err, dbname, strlen(dbname), (ub4) OCI_DEFAULT);
    if (ret != OCI_SUCCESS)
    {
        std::cout << "Failed to OCIServerAttach" << std::endl;
        goto clean;
    }

  clean:
    if (env) OCIHandleFree(env, OCI_HTYPE_ENV   );
    if (err) OCIHandleFree(err, OCI_HTYPE_ERROR );
    if (srv) OCIHandleFree(srv, OCI_HTYPE_SERVER);
    if (svc) OCIHandleFree(svc, OCI_HTYPE_SVCCTX);

    return (int)ret;
}
}

int select()
{
    OCIEnv *env = NULL;
    OCIError *err = NULL;
    OCIServier *srv = NULL;
    OCISvcCtx *svc = NULL;
    OCISession *ses = NULL;

    text username[30] = "damo";
    text password[30] = "damo";
    text dbname[30] = "orclpdb1";

    sword ret;

    ret = OCIEnvCreate(&env, OCI_DEFAULT, 0, 0, 0, 0, 0, 0);
    if (ret != OCI_SUCCESS)
    {
        std::cout << "Failed to OCIEnvCreate" << std::endl;
        goto clean;
    }

    OCIHandleAlloc(env, (dvoid**)&err, OCI_HTYPE_ERROR, 0, 0);
    OCIHandleAlloc(env, (dvoid**)&srv, OCI_HTYPE_SERVER, 0, 0);
    OCIHandleAlloc(env, (dvoid**)&svc, OCI_HTYPE_SVCCTX, 0, 0);
    OCIHandleAlloc(env, (dvoid**)&ses, OCI_HTYPE_SESSION, 0, 0);

    ret = OCIServerAttach(srv, err, dbname, strlen(dbname), (ub4) OCI_DEFAULT);
    if (ret != OCI_SUCCESS)
    {
        std::cout << "Failed to OCIServerAttach" << std::endl;
        goto clean;
    }

  clean:
    if (env) OCIHandleFree(env, OCI_HTYPE_ENV   );
    if (err) OCIHandleFree(err, OCI_HTYPE_ERROR );
    if (srv) OCIHandleFree(srv, OCI_HTYPE_SERVER);
    if (svc) OCIHandleFree(svc, OCI_HTYPE_SVCCTX);

    return (int)ret;
}
