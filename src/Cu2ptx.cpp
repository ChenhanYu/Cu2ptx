#include <iostream>

#define ENDL " \\n\\t\n"

class Cu2ptx {
  public:
		Cu2ptx() {};
		void Init();
		void Term();
		void Dreg( char *name, int n );
		void Preg( char *name, int n );
		void Dshared_ld( char *reg, char *ptr, int n );
    void Daxpy( char *y, char *alpha, char *x, int n );
};

void Cu2ptx::Init() { std::cout << "asm volatile (\n"; }
void Cu2ptx::Term() { std::cout << ");\n"; }


void Cu2ptx::Dreg( char *name, int n ) { std::cout << ".reg .f64 %" << name << "<" << n << ">;" <<  ENDL; }
void Cu2ptx::Preg( char *name, int n ) { std::cout << ".reg .s64 %" << name << "<" << n << ">;" <<  ENDL; }

void Cu2ptx::Dshared_ld( char *reg, char *ptr, int n )
{
	for ( int i = 0; i < n; i++ )
    std::cout << "ld.shared.f64 %" << reg << i << ", %" << ptr << "+" <<  i * 8 << "];" << ENDL;
}

void Cu2ptx::Daxpy( char *y, char *alpha, char *x, int n )
{
	for ( int i = 0; i < n; i++ )
    std::cout << "fma.rn.f64 %" << y << i << ", %" << alpha << ", %" << x << i << ", %" << y << i << ";" << ENDL;
}

int main() {
  Cu2ptx handle;

	handle.Init();

	handle.Dreg( "c0", 8 );
	handle.Dreg( "a", 8 );
	handle.Dreg( "b", 8 );
	handle.Dreg( "alpha", 1 );

	handle.Dshared_ld( "c0", "f", 8 );
	handle.Daxpy( "c0", "alpha", "a", 8 );

  handle.Term();

	return 0;
}

