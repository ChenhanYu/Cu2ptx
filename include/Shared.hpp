class Shared {
  public:
    static void ld_f64( char *reg, char *ptr, int n );
    static void st_f64( char *ptr, char *reg, int n );
};

void Shared::ld_f64( char *reg, char *ptr, int n )
{
	for ( int i = 0; i < n; i++ ) {
    std::cout << BEGL;
    std::cout << "ld.shared.f64 %" << reg << i << ", [%" << ptr << "+" <<  i * 8 << "];";
    std::cout << ENDL;
  }
}

void Shared::st_f64( char *ptr, char *reg, int n )
{
	for ( int i = 0; i < n; i++ ) {
    std::cout << BEGL;
    std::cout << "st.shared.f64 [%" << ptr << "+" <<  i * 8 << "], %" << reg << i << ";";
    std::cout << ENDL;
  }
}

