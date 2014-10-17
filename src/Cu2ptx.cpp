#include <iostream>
#define BEGL "  \""
#define ENDL "  \\n\\t\"\n"

#include <Global.hpp>
#include <Shared.hpp>

class Cu2ptx {
  public:
		Cu2ptx() {};
		void Init();
		void Term();
		void Dreg( char *name, int n );
		void Preg( char *name, int n );
    void Output_beg( char *type, char *name, int i );
    void Output_add( char *type, char *name, int i );
    void Input_beg( char *type, char *name, int i );
    void Input_add( char *type, char *name, int i );
    void Dmov( char *tar, char *src );
    void Daxpy( char *y, char *alpha, char *x, int n );
};

void Cu2ptx::Init() { std::cout << "asm volatile (\n"; }
void Cu2ptx::Term() { std::cout << ");\n"; }

void Cu2ptx::Dreg( char *name, int n ) {
  std::cout << BEGL;
  if ( n == 1 ) {
    std::cout << ".reg .f64 %" << name << ";";
  }
  else {
    std::cout << ".reg .f64 %" << name << "<" << n << ">;";
  }
  std::cout << ENDL;
}
void Cu2ptx::Preg( char *name, int n ) {
  std::cout << BEGL;
  if ( n == 1 ) {
    std::cout << ".reg .s64 %" << name << ";";
  }
  else {
    std::cout << ".reg .s64 %" << name << "<" << n << ">;";
  }
  std::cout << ENDL;
}

void Cu2ptx::Dmov( char *tar, char *src )
{
  std::cout << BEGL;
  std::cout << "mov.f64 %" << tar << ", %" << src << ";";
  std::cout << ENDL;
}

void Cu2ptx::Output_beg( char *type, char *name, int i )
{
  std::cout << "  : \"" << type << "\"( " << name << " )  // %" << i << "\n";
}

void Cu2ptx::Output_add( char *type, char *name, int i )
{
  std::cout << "  , \"" << type << "\"( " << name << " )  // %" << i << "\n";
}

void Cu2ptx::Input_beg( char *type, char *name, int i )
{
  std::cout << "  : \"" << type << "\"( " << name << " )  // %" << i << "\n";
}

void Cu2ptx::Input_add( char *type, char *name, int i )
{
  std::cout << "  , \"" << type << "\"( " << name << " )  // %" << i << "\n";
}

void Cu2ptx::Daxpy( char *y, char *alpha, char *x, int n )
{
	for ( int i = 0; i < n; i++ ) {
    std::cout << BEGL;
    std::cout << "fma.rn.f64 %" << y << i << ", %" << alpha << ", %" << x << i << ", %" << y << i << ";";
    std::cout << ENDL;
  }
}

void gen_axpy_asm_1_1 () {
  Cu2ptx handle;

	handle.Init();

  handle.Preg( "px", 1 );
  handle.Preg( "py", 1 );
  handle.Dreg( "ry", 8 );
  handle.Dreg( "rx", 8 );
  handle.Dreg( "alpha", 1 );

  Global::cvta_u64( "py", "0" );
  handle.Dmov( "alpha", "1" );
  Global::cvta_u64( "px", "2" );

  Global::ld_f64( "ry", "py", 0, 8 );
  Global::ld_f64( "rx", "px", 1, 8 );
  handle.Daxpy( "ry", "alpha", "rx", 8 );
  Global::st_f64( "py", "ry", 8 );

  // Input Output
  handle.Output_beg(   "+l", "y", 0 );
  handle.Input_beg( "d", "alpha", 1 );
  handle.Input_add(     "l", "x", 2 );

  handle.Term();

}


int main() {

  gen_axpy_asm_1_1();

	return 0;
}

