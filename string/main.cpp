#include <iostream>
#include <string>
#include <algorithm>
//#include <thread>

using namespace std;

//class A
//{
// public:
//  thread thd;
//  
//  static void print(void* pArg)
//  {
//    cout << "hello" << endl;
//  }
//
//  void startThread()
//  {
//    thd = thread(A::print, this);
//  }
//}; 
//
int testStringUpper();

int testStringOperation();

int main(int argc, char* argv[])
{
  int ret = -1;
  /* Test 1 */
  //A* a = new A();
  //a->startThread();
  //int i = 0;
  //while (true)
  //{
  //  i++;
  //}

  /* Test 2 */
  //std::string tmp = "DAMO";
  //char post[2] = {0x01, 0x01};
  //tmp.append(post);
  //std::cout << "[" << std::oct << tmp.c_str() << "]" << tmp.size() << std::endl << std::dec;

  //for (int i=0; i<tmp.size(); i++)
  //  std::cout << (int)tmp[i] << std::endl;
  //std::string str = "";

  //if (str.empty() == NULL)
  //{
  //  std::cout << "empty" << std::endl;
  //}
  //else
  //{
  //  std::cout << "not empty" << std::endl;
  //}
  //if (false == NULL)
  //{
  //  std::cout << "Same" << std::endl;
  //}

  //std::string str = "1.3.4.5.6.";
  //if (str.substr(str.length()-1, str.length()).compare(".") == 0)
  //{
  //  str += "X";
  //}

  //std::cout << str.c_str() << std::endl;
  //std::string time = "202005260000";
  //std::cout << time.length() << std::endl;
  //std::cout << time.substr(0,8) << std::endl;

  // Test std::string upper
  ret = testStringUpper();
  if (ret != 0)
  {
    std::cout << "Failed to testStringUpper()" << std::endl;
  }
  else
  {
    std::cout << "Success to testStringUpper()" << std::endl;
  }

  ret = testStringOperation();
  if (ret != 0)
  {
    return -1;
  }

  return 0;
}

int testStringUpper()
{
  std::string str = "abcdefg12345ABCDEFG";
  std::cout << "String : " << str.c_str() << std::endl;

  std::transform(str.begin(), str.end(), str.begin(), ::toupper);
  std::cout << "String : " << str.c_str() << std::endl;

  return 0;
}

int testStringOperation()
{
   std::string str = "asdasd";

   str += "12345";

   std::cout << str.c_str() << std::endl;

  return 0;
}
