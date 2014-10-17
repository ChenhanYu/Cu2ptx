CC = icc
CXX = icpc
NVCC = nvcc

ARCH = ar
ARCHFLAGS = cr
RANLIB = ranlib

CFLAGS = -O3
NVCCFLAGS = -O4 -arch sm_35 
#NVCCFLAGS = -O4 -arch sm_35 --maxrregcount=128

LIBGNF = $(GNF_DIR)/lib/libgnf.a

CUDA_DIR = $(TACC_CUDA_DIR)

LDFLAGS = -I$(CUDA_DIR)/include -I$(GNF_DIR)/include

LDLIBS = $(LIBGNF) -L$(CUDA_DIR)/lib64 -lcudart -lcublas -lm
