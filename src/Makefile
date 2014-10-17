include $(CU2PTX_DIR)/make.inc

D_CC_SRC=
D_CU_SRC=
D_CPP_SRC=

D_CC_OBJ=$(D_CC_SRC:.c=.o)
D_CU_OBJ=$(D_CU_SRC:.cu=.cuo)
D_CPP_OBJ=$(D_CPP_SRC:.cpp=.o)

executable: $(CU2PTX_DIR)/bin/test_Cu2ptx.x $(CU2PTX_DIR)/bin/test_axpy.x

all: $(LIBCU2PTX) executable

$(LIBCU2PTX): $(D_CC_OBJ) $(D_CU_OBJ) $(D_CPP_OBJ)
	$(ARCH) $(ARCHFLAGS) $@ $(D_CC_OBJ) $(D_CU_OBJ) $(D_CPP_OBJ)
	$(RANLIB) $@

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

%.cuo: %.cu
	$(NVCC) $(NVCCFLAGS) -c $< -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

$(CU2PTX_DIR)/bin/test_Cu2ptx.x: Cu2ptx.cpp
	$(CXX) $(CFLAGS) $< -o $@ $(LDFLAGS) $(LDLIBS)

$(CU2PTX_DIR)/bin/test_axpy.x: test_axpy.cu
	$(NVCC) $(NVCCFLAGS) $< -o $@ $(LDFLAGS) $(LDLIBS)

clean: 
	rm -f *~ $(CU2PTX_DIR)/bin/*.x $(CU2PTX_DIR)/bin/*~ $(CU2PTX_DIR)/lib/*.a $(CU2PTX_DIR)/*~ $(CU2PTX_DIR)/include/*~
