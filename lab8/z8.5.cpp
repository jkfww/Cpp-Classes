/*Operatory arytmetyczne nie będą miały jak automatycznie wydedukować typu T : 
template<typename T,typename LHS,typename RHS > Add<T,LHS,RHS> operator+(const LHS &l, const RHS &r)
ponieważ, typ T nie pojawia się w argumentach wywołania. Zaimplementuj dodatkową klasę 
Expr "opakowującej" wyrażenia, która będzie przenosiła informację o typie. 
Przedstaw przykłady całkowania funkcji z użyciem zmiennej innego typu niż double.*/

#include<cmath>
#include <iostream>
  
template<typename F> double integrate(F f,double  min,double max,double ds) {
  double integral=.0;
  for(double x=min;x<max;x+=ds) {
    integral+=f(x);
  }
  return integral*ds;
};

template <typename T>
class Variable {
public:
  double operator()(T x) {
    return x;
  }
};


class Constant {
  double _c;
public:
  Constant(double c) :_c(c){};
  double operator()(double x) {return _c;}
};



/* dodawanie */


template<typename LHS,typename RHS > class AddExpr {
  LHS _lhs;
  RHS _rhs;
public:
  AddExpr(const LHS &l,const RHS &r) :_lhs(l),_rhs(r) {};
  double operator()(double x) {
    return _lhs(x)+_rhs(x);
  }
}; 

template<typename LHS,typename RHS > 
AddExpr<LHS,RHS>  operator+(const LHS &l,
			const RHS &r) {
  return AddExpr<LHS,RHS>(l,r);
};   


template<typename LHS > 
AddExpr<LHS,Constant>  operator+(const LHS &l,
			double r) {
  return AddExpr<LHS,Constant>(l,Constant(r));
};   

template<typename RHS > 
AddExpr<Constant,RHS>  operator+(double l,
			const RHS &r) {
  return AddExpr<Constant,RHS>(Constant(l),r);
};   


/* dzielenie */

template<typename LHS,typename RHS > class DivExpr {
  LHS _lhs;
  RHS _rhs;
public:
  DivExpr(const LHS &l,const RHS &r) :_lhs(l),_rhs(r) {};
  double operator()(double x) {
    return _lhs(x)/_rhs(x);
  }
}; 

template<typename LHS,typename RHS > 
DivExpr<LHS,RHS>  operator/(const LHS &l,
			const RHS &r) {
  return DivExpr<LHS,RHS>(l,r);
};   


template<typename LHS > 
DivExpr<LHS,Constant>  operator/(const LHS &l,
			double r) {
  return DivExpr<LHS,Constant>(l,Constant(r));
};   

template<typename RHS > 
DivExpr<Constant,RHS>  operator/(double l,
			const RHS &r) {
  return DivExpr<Constant,RHS>(Constant(l),r);
};   


template<typename Arg> class SinExpr{ 
  Arg _arg;
public:
  SinExpr(const Arg& arg) :_arg(arg) {};
  double operator()(double x) {return sin(_arg(x));}
};

template<typename Arg> SinExpr<Arg> sin(const Arg&a) {
  return SinExpr<Arg>(a);}

//-------------------------------------------------------
template<typename T,typename R = Variable<T> > class Expr {
  R _rep;
 public:
  Expr() {};
  Expr(R rep):_rep(rep) {};
  T operator()(T x) {return _rep(x);}
  R rep() const {return _rep;};
};
//-------------------------------------------------------

int main(){
    using namespace std;
    Variable <int>x;
    cout<<integrate(1./sin(x+ 1.) ,0,1,0.001)<<endl;
}