#include <iostream>
#include <string>

void pbanner(std::string str) {
  std::cout << "*******************************************************"
            << std::endl;
  std::cout << str << std::endl;
  std::cout << "*******************************************************"
            << std::endl;
}
/**
 *a class with DEFAULT constructors
 */
class dummy {
public:
  void setVal(const int &inval);
  void setStr(const std::string &inval);
  int getVal() const;
  std::string getStr() const;

private:
  int m_val;
  std::string m_str;
};

void dummy::setVal(const int &inval) { m_val = inval; }

void dummy::setStr(const std::string &inval) { m_str = inval; }

int dummy::getVal() const { return m_val; }

std::string dummy::getStr() const { return m_str; }

/**
 * class with DEFINED constructors
 */
class dummy1 {
public:
  dummy1();
  ~dummy1();
  dummy1(dummy1 &other);
  dummy1& operator=(const dummy1 &rhs);
  void setVal(const int &inval);
  void setStr(const std::string &inval);
  int getVal() const;
  std::string getStr() const;

private:
  int m_val;
  std::string m_str;
};

dummy1::dummy1() { std::cout << "dummy1 constructor called" << std::endl; }

dummy1::~dummy1() { std::cout << "dumm1 destructor called" << std::endl; }
dummy1::dummy1(dummy1& other) {
  this-> m_val = other.m_val;
  this-> m_str = other.m_str;
  std::cout << "dummy1 copy constructor called" << std::endl;
}

dummy1& dummy1::operator=(const dummy1 &rhs) {
  this-> m_val = rhs.m_val;
  this-> m_str = rhs.m_str;
  std::cout << "dummy1 operator= called" << std::endl;
  return (*this);
}
void dummy1::setVal(const int &inval) { m_val = inval; }

void dummy1::setStr(const std::string &inval) { m_str = inval; }

int dummy1::getVal() const { return m_val; }

std::string dummy1::getStr() const { return m_str; }

int main() {
  pbanner("With all default constructors");
  dummy c1, c2;
  c1.setStr("dummy 1");
  c2.setStr("dummy 2");
  c1.setVal(1);
  c2.setVal(2);
  std::cout << "====== Initially =============" << std::endl;
  std::cout << "c1.m_str: " << c1.getStr() << "  c2.m_str: " << c2.getStr()
            << std::endl;
  std::cout << "c1.m_val: " << c1.getVal() << "  c2.m_val: " << c2.getVal()
            << std::endl;

  // now assign c2 to c1
  // this will work because compiler will generate move asignment operator
  c1 = c2;

  std::cout << "====== after c1=c2 =============" << std::endl;
  std::cout << "c1.m_str: " << c1.getStr() << "  c2.m_str: " << c2.getStr()
            << std::endl;
  std::cout << "c1.m_val: " << c1.getVal() << "  c2.m_val: " << c2.getVal()
            << std::endl;

  // this will work because compiler generated  copy constructor
  dummy c3(c2);
  std::cout << "====== after c3(c2) =============" << std::endl;
  std::cout << "c2.m_str: " << c2.getStr() << "  c3.m_str: " << c3.getStr()
            << std::endl;
  std::cout << "c2.m_val: " << c2.getVal() << "  c3.m_val: " << c3.getVal()
            << std::endl;

  pbanner("With defined constructors");
  dummy1 d1, d2;
  d1.setStr("dummy 1");
  d2.setStr("dummy 2");
  d1.setVal(1);
  d2.setVal(2);
  std::cout << "====== Initially =============" << std::endl;
  std::cout << "d1.m_str: " << d1.getStr() << "  d2.m_str: " << d2.getStr()
            << std::endl;
  std::cout << "d1.m_val: " << d1.getVal() << "  d2.m_val: " << d2.getVal()
            << std::endl;

  // now assign d2 to d1
  // this will work because compiler will generate move asignment operator
  d1 = d2;

  std::cout << "====== after d1=d2 =============" << std::endl;
  std::cout << "d1.m_str: " << d1.getStr() << "  d2.m_str: " << d2.getStr()
            << std::endl;
  std::cout << "d1.m_val: " << d1.getVal() << "  d2.m_val: " << d2.getVal()
            << std::endl;

  // this will work because compiler generated  copy constructor
  dummy1 d3(d2);
  std::cout << "====== after d3(d2) =============" << std::endl;
  std::cout << "d2.m_str: " << d2.getStr() << "  d3.m_str: " << d3.getStr()
            << std::endl;
  std::cout << "d2.m_val: " << d2.getVal() << "  d3.m_val: " << d3.getVal()
            << std::endl;

  return 0;
}
