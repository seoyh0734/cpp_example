#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>

std::vector<std::string> split(std::string str, char delimiter)
{
  std::vector<std::string> internal;

  std::stringstream ss(str);
  std::string temp;

  while (getline(ss, temp, delimiter)) {
      internal.push_back(temp);
  }

  return internal;
}

int compareVersion(std::string lVersion, std::string rVersion)
{
  int ret = -1;

  std::vector<std::string> lVersionParts = split(lVersion, '.');
  std::vector<std::string> rVersionParts = split(rVersion, '.');
  std::cout << lVersion << " vs " << rVersion << std::endl;
/*
  if (lVersionParts.size() != 4 ||
      rVersionParts.size() != 4)
  {
    throw std::invalid_argument("invalid version info");
  }
*/
  for (unsigned int i=0; i<lVersionParts.size(); i++)
  {
    int lVer = atoi(lVersionParts[i].c_str());
    int rVer = atoi(rVersionParts[i].c_str());

    if (lVer > rVer)
    {
  std::cout << lVer << " > " << rVer << std::endl;
      return -1;
    }
    else if (lVer < rVer)
    {
  std::cout << lVer << " < " << rVer << std::endl;
      return 1;
    }
    else
    {
  std::cout << lVer << " = " << rVer << std::endl;
      continue;
    }
  }

  std::cout << "same" << std::endl;
  return 0;
}

std::string convertVersion(std::string version)
{
  std::vector<std::string> verParts = split(version, '.');

  if (verParts.size() == 4)
  {
    return version;
  }
  else if (verParts.size() == 2)
  {
    size_t strLeng = verParts[1].size();
    if (verParts[0].compare("3") == 0)
    {
      if (verParts[1].find("05") == 0)
      {
        return std::string(verParts[0] + ".0.5." + verParts[1].substr(2, strLeng));
      }
      else if (verParts[1].find("011") == 0)
      {
        return std::string(verParts[0] + ".0.11." + verParts[1].substr(3, strLeng));
      }
      else if (verParts[1].find("012") == 0)
      {
        return std::string(verParts[0] + ".0.12." + verParts[1].substr(3, strLeng));
      }
      else if (verParts[1].find("013") == 0)
      {
        return std::string(verParts[0] + ".0.13." + verParts[1].substr(3, strLeng));
      }
      else if (verParts[1].find("014") == 0)
      {
        return std::string(verParts[0] + ".0.14." + verParts[1].substr(3, strLeng));
      }
      else if (verParts[1].find("015") == 0)
      {
        return std::string(verParts[0] + ".0.15." + verParts[1].substr(3, strLeng));
      }
      else if (verParts[1].find("025") == 0)
      {
        return std::string(verParts[0] + ".0.25." + verParts[1].substr(3, strLeng));
      }
      else
      {
        return "";
      }
    }
    else
    {
      return "";
    }
  }

  return "";
}

bool isSupport(std::string version, std::string min, std::string max)
{
  std::string minVersion = convertVersion(min);
  std::string maxVersion = convertVersion(max);

  if (minVersion.empty() == true ||
      maxVersion.empty() == true)
  {
    return false;
  }

  if (compareVersion(version, minVersion) > 0 ||
      compareVersion(version, maxVersion) < 0)
  {
    return false;
  }

  return true;
}

int main(int argc, char* argv[])
{
  int ret = -1;
  //std::string ver = "3.0.15.10";
  //std::string min1 = "0.0.0.0";
  //std::string max1 = "3.0145";
  //std::string min2 = "3.0.14.6";
  //std::string max2 = "999.999.999.999";

  //std::cout << "case 1 : " << isSupport(ver, min1, max1) << std::endl;
  //std::cout << "case 2 : " << isSupport(ver, min2, max2) << std::endl;

  std::string str1 = "a";
  std::wstring str2 = L"a";

  std::string convStr;
  convStr.assign(str2.begin(), str2.end());

  std::cout << convStr.c_str() << std::endl;
  std::cout << str1.c_str() << std::endl;

  if (str1.compare(convStr) == 0)
  {
    std::cout << "same" << std::endl;
    
  }

  return ret;
}
