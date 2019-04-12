#include "tp_data_features/members/FeaturesMember.h"

namespace tp_data_features
{
//##################################################################################################
FeaturesMember::FeaturesMember(const std::string& name, const tp_utils::StringID& type):
  tp_data::AbstractMember(name, type)
{

}

//##################################################################################################
FeaturesMember::~FeaturesMember() = default;

}
