class Global {
  public:
    static void cvta_u64( char *tar, char *src );
    static void ld_f64( char *reg, char *ptr, int nc, int n );
    static void st_f64( char *ptr, char *reg, int n );

};


void Global::cvta_u64( char *tar, char *src )
{
  std::cout << BEGL;
  std::cout << "cvta.to.global.u64 %" << tar << ", %" << src << ";";
  std::cout << ENDL;
}


void Global::ld_f64( char *reg, char *ptr, int nc, int n )
{
	for ( int i = 0; i < n; i++ ) {
    std::cout << BEGL;
    if ( nc ) {
      std::cout << "ld.global.nc.f64 %" << reg << i << ", [%" << ptr << "+" <<  i * 8 << "];";
    }
    else {
      std::cout << "ld.global.f64 %" << reg << i << ", [%" << ptr << "+" <<  i * 8 << "];";
    }
    std::cout << ENDL;
  }
}

void Global::st_f64( char *ptr, char *reg, int n )
{
	for ( int i = 0; i < n; i++ ) {
    std::cout << BEGL;
    std::cout << "st.global.f64 [%" << ptr << "+" <<  i * 8 << "], %" << reg << i << ";";
    std::cout << ENDL;
  }
}

