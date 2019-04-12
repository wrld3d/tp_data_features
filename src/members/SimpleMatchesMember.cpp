#include "tp_data_features/members/SimpleMatchesMember.h"

namespace tp_data_features
{
const std::string SimpleMatchesMember::extension{"bin"};

//##################################################################################################
SimpleMatchesMember::SimpleMatchesMember(const std::string& name):
  MatchesMember(name, matchesSID())
{

}

//##################################################################################################
SimpleMatchesMember::~SimpleMatchesMember() = default;

//##################################################################################################
SimpleMatchesMember* SimpleMatchesMember::fromData(std::string& error, const std::string& data)
{
  if((data.size()%(9*4)) != 0)
  {
    error = "Input data wrong size.";
    return nullptr;
  }

  size_t nMatches = data.size()/(9*4);

  auto src = data.data();
  auto readFloat = [&]()
  {
    float word{0.0f};
    static_assert (sizeof(word)==4, "This only works with 32bit words.");
    memcpy(&word, src, 4);
    src+=4;
    return word;
  };
  auto readInt = [&]()
  {
    int32_t word{0};
    static_assert (sizeof(word)==4, "This only works with 32bit words.");
    memcpy(&word, src, 4);
    src+=4;
    return word;
  };

  auto member = new SimpleMatchesMember();
  member->data.resize(nMatches);
  for(size_t n=0; n<nMatches; n++)
  {
    auto& m = member->data.at(n);
    m.indexA     = size_t(readInt());
    m.indexB     = size_t(readInt());

    m.coord2DA.x = readFloat();
    m.coord2DA.y = readFloat();

    m.coord2DB.x = readFloat();
    m.coord2DB.y = readFloat();

    m.coord3D.x  = readFloat();
    m.coord3D.y  = readFloat();
    m.coord3D.z  = readFloat();
  }
  return member;
}

//##################################################################################################
std::string SimpleMatchesMember::toData() const
{
  auto bytes = (data.size()*9)*4;

  std::string output;
  output.resize(bytes);
  auto dst = output.data();
  auto addWord = [&](auto word)
  {
    static_assert (sizeof(word)==4, "This only works with 32bit words.");
    memcpy(dst, &word, 4);
    dst+=4;
  };

  for(const auto& m : data)
  {
    addWord(int32_t(m.indexA));
    addWord(int32_t(m.indexB));

    addWord(float(m.coord2DA.x));
    addWord(float(m.coord2DA.y));

    addWord(float(m.coord2DB.x));
    addWord(float(m.coord2DB.y));

    addWord(float(m.coord3D.x));
    addWord(float(m.coord3D.y));
    addWord(float(m.coord3D.z));
  }

  return output;
}

//##################################################################################################
void SimpleMatchesMember::copyData(const SimpleMatchesMember& other)
{
  data = other.data;
}

}
