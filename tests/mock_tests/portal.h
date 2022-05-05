#pragma once

#define private public
#define protected public

#include "aclorch.h"
#include "crmorch.h"
#include "sfloworch.h"
#include "directory.h"

#undef protected
#undef private

struct Portal
{
    struct AclRuleInternal
    {
        static sai_object_id_t getRuleOid(const AclRule *aclRule)
        {
            return aclRule->m_ruleOid;
        }

        static const map<sai_acl_entry_attr_t, SaiAttrWrapper> &getMatches(const AclRule *aclRule)
        {
            return aclRule->m_matches;
        }

        static const map<sai_acl_entry_attr_t, SaiAttrWrapper> &getActions(const AclRule *aclRule)
        {
            return aclRule->m_actions;
        }
    };

    struct AclOrchInternal
    {
        static const map<sai_object_id_t, AclTable> &getAclTables(const AclOrch *aclOrch)
        {
            return aclOrch->m_AclTables;
        }
    };

    struct CrmOrchInternal
    {
        static const std::map<CrmResourceType, CrmOrch::CrmResourceEntry> &getResourceMap(const CrmOrch *crmOrch)
        {
            return crmOrch->m_resourcesMap;
        }

        static std::string getCrmAclKey(CrmOrch *crmOrch, sai_acl_stage_t stage, sai_acl_bind_point_type_t bindPoint)
        {
            return crmOrch->getCrmAclKey(stage, bindPoint);
        }

        static std::string getCrmAclTableKey(CrmOrch *crmOrch, sai_object_id_t id)
        {
            return crmOrch->getCrmAclTableKey(id);
        }

        static void getResAvailableCounters(CrmOrch *crmOrch)
        {
            crmOrch->getResAvailableCounters();
        }
    };

    struct SflowOrchInternal
    {
        static bool getSflowStatusEnable(SflowOrch &obj)
        {
            return obj.m_sflowStatus;
        }

        static SflowRateSampleMap getSflowSampleMap(SflowOrch &obj)
        {
            return obj.m_sflowRateSampleMap;
        }

        static SflowPortInfoMap getSflowPortInfoMap(SflowOrch &obj)
        {
            return obj.m_sflowPortInfoMap;
        }
    };

    struct DirectoryInternal
    {
        template <typename T>
        static void clear(Directory<T> &obj)
        {
            obj.m_values.clear();
        }

        template <typename T>
        static bool empty(Directory<T> &obj)
        {
            return obj.m_values.empty();
        }
    };
};
