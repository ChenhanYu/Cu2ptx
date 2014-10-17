CC = icc
CXX = icpc
NVCC = nvcc

ARCH = ar
ARCHFLAGS = cr
RANLIB = ranlib

CFLAGS = -O3
NVCCFLAGS = -O4 -arch sm_35 
#NVCCFLAGS = -O4 -arch sm_35 --maxrregcount=128

LIBGNF = $(CU2PTX_DIR)/lib/libgnf.a

CUDA_DIR = $(TACC_CUDA_DIR)

LDFLAGS = -I$(CUDA_DIR)/include -I$(GNF_DIR)/include

LDLIBS = $(LIBCU2PTX) -L$(CUDA_DIR)/lib64 -lcudart -lcublas -lm
