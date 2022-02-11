# Chapter 01 C언어 기반의 C++
### C++ 입출력 방식
  * 헤더파일 선언문 #include <iostream>
  * std::cout과 <<, std::cin과 >>를 이용한 입출력
    - C언어의 printf, scanf 함수와 달리 별로의 출력포맷을 지정하지 않아도 데이터 형식에 따라 출력
  * std::endl을 이용한 개행
  * 변수의 선언은 어디서든 가능
  
### 함수 오버로딩
  *  _'함수의 이름'_ 과 _'매개변수의 선언'_ 에 대한 정보를 활용하여 호출 함수를 구분한다.
  ```C++
  int MyFunc(char c) { ... }
  int MyFunc(int n1, int n2) { ... }
  ```
  
### 매개변수 디폴트 값 설정
  * 함수호출 시 인자를 전달하지 않으면 설정한 디폴트 값으로 전달한다.
    - 전달되는 인자는 왼쪽에서부터 채워지고, 부족분은 디폴트 값으로 채워진다.
  * 디폴트 값은 함수의 선언 부분에만 표현하면 된다.
  ```C++
  int MyFuncOne(int num=7);
  int MyFuncTwo(int num1=5, int num2=7);
  ```
  
### 인라인(inline) 함수
  * 매크로 함수
    - 일반적인 함수에 비해 실행속도의 이점이 있다.
    - 복잡한 함수를 매크로의 형태로 정의하는데 한계가 있다.
    - 전처리기에 의해서 처리된다.
  * C++ 기반 인라인 함수
    - 컴파일러에 의해서 처리된다.
    - 매개변수 자료형에 의존적이다. 데이터 변환이 이루어지지 않아 데이터 손실이 발생할 수 있다.
      + 템플릿을 이용하여 해결 가능하다.
  ```C++
  #include <iostream>
  #define SQUARE(X) ((X)*(X))   // 매크로 함수
  
  inline int SQUARE(int X)      // 인라인 함수
  {
  return X*X
  }
  
  int main(void)
  {
  std::cout<<SQUARE(5)<<std::endl;
  return 0;
  }
  ```
  
  ### 이름공간(namespace)에 대한 소개
  ```C++
  #include <iostream>
  
  namespace BestComImpl
  {
  void SimpleFunc(void);
  }
  
  namespace ProgComImpl
  {
  void SimpleFunc(void)
  }
  
  int main(void)
  {
  BestComImpl::SimpleFunc();    // 이름공간 BestComImpl에 선언된 SimpleFunc() 호출 -> BestCom이 정의한 함수
  ProgComImpl::SimpleFunc();    // 이름공간 ProgComImpl에 선언된 SimpleFunc() 호출 -> ProgCom이 정의한 함수
  return 0;
  }
  
  void BestComImpl::SimpleFunc(void)
  {
  std::cout<<"BestCom이 정의한 함수"<<std::endl;
  }
  
  void ProgComImpl::SimpleFunc(void)
  {
  std::cout<<"ProgCom이 정의한 함수"<<std::endl;
  }
  ```
