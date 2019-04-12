#ifndef tp_data_features_FeaturesMember_h
#define tp_data_features_FeaturesMember_h

#include "tp_data_features/Globals.h"

#include "tp_data/AbstractMember.h"

namespace tp_data_features
{

//##################################################################################################
class FeaturesMember : public tp_data::AbstractMember
{
public:
  //################################################################################################
  FeaturesMember(const std::string& name, const tp_utils::StringID& type);

  //################################################################################################
  ~FeaturesMember() override;

};

}

#endif
