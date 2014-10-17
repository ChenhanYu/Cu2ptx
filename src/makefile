include $(GNF_DIR)/make.inc

D_CC_SRC=evaluate_gold.c
#D_CU_SRC=kernel_32_32_8_8_8.cu kernel_cublas.cu
#D_CU_SRC=kernel_cublas.cu kernel_64_64_8_16_16.cu kernel_32_32_8_8_8_v2.cu
D_CU_SRC=kernel_cublas.cu kernel_64_64_8_16_16.cu ks_128_8_64_8_32.cu
D_CPP_SRC=CudaHandle.cpp 
#D_CPP_SRC=CudaHandle.cpp 

D_CC_OBJ=$(D_CC_SRC:.c=.o)
D_CU_OBJ=$(D_CU_SRC:.cu=.o)
D_CPP_OBJ=$(D_CPP_SRC:.cpp=.o)

all: $(LIBGNF) test.x

$(LIBGNF): $(D_CC_OBJ) $(D_CU_OBJ) $(D_CPP_OBJ)
	$(ARCH) $(ARCHFLAGS) $@ $(D_CC_OBJ) $(D_CU_OBJ) $(D_CPP_OBJ)
	$(RANLIB) $@


test.x: test_handle.cpp $(LIBGNF)
	$(CXX) $(CFLAGS) test_handle.cpp -o test.x $(LDFLAGS) $(LDLIBS)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cu
	$(NVCC) $(NVCCFLAGS) -c $< -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

clean:
	rm *.o $(GNF_DIR)/lib/libgnf.a
