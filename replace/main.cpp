#include <iostream>

int replace(std::string& output, std::string origin, std::string from, std::string to) {
  int findPos = origin.find(from);
  if (findPos == std::string::npos) {
    return 11;
  }

  output = origin.replace(origin.find(from), from.length(), to);
  return 0;
}

int main(int argc, char** argv) {
  std::string path = "/test/damo_lic/a.b/123_214/damo_lic.cer3";

  std::string from = "damo_lic.cer5";
  std::string to = "damo_lic_info";

  std::string output;

  int ret = replace(output, path, from, to);
  if (ret != 0) {
    return ret;
  }
  std::cout << output << std::endl;
  return 0;
}
