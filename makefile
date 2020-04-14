# All of the sources participating in the build are defined here
-include smc-compute/ops/ops.mk
-include smc-compute/smc-compute.mk
-include objects.mk

#Add test program to the build variables
CPP_SRCS += \
#test-code.cpp 

OBJS += \
#test-code.o 

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif


# Add inputs and outputs from these tool invocations to the build variables 
# All Target
all: matrix_100_tran matrix_1000_tran matrix_10_tran30 matrix_100_tran30 matrix_1000_tran30 randbit32 randbit60

randbit60: $(OBJS) $(USER_OBJS) 
	g++ -c -w randbit60.cpp 
	g++ -o randbit60 randbit60.o $(OBJS) $(USER_OBJS) $(LIBS) 

randbit32: $(OBJS) $(USER_OBJS) 
	g++ -c -w randbit32.cpp 
	g++ -o randbit32 randbit32.o $(OBJS) $(USER_OBJS) $(LIBS) 

mul_1000_tran: $(OBJS) $(USER_OBJS) 
	g++ -c -w mul_1000_tran.cpp 
	g++ -o mul_1000_tran mul_1000_tran.o $(OBJS) $(USER_OBJS) $(LIBS) 
# replace the line above with this one for multi-threaded programs
#	g++ -o test-code test-code.o -I ./ompi/include/ompi $(OBJS) $(USER_OBJS) $(LIBS) -L ./ompi/lib/ompi -L ./ompi/lib/ompi/default -lort -lrt -lboost_thread 
matrix_10_tran: $(OBJS) $(USER_OBJS) 
	g++ -c -w matrix_10_tran.cpp 
	g++ -o matrix_10_tran matrix_10_tran.o $(OBJS) $(USER_OBJS) $(LIBS) 

matrix_100_tran: $(OBJS) $(USER_OBJS) 
	g++ -c -w matrix_100_tran.cpp 
	g++ -o matrix_100_tran matrix_100_tran.o $(OBJS) $(USER_OBJS) $(LIBS) 

matrix_1000_tran: $(OBJS) $(USER_OBJS) 
	g++ -c -w matrix_1000_tran.cpp 
	g++ -o matrix_1000_tran matrix_1000_tran.o $(OBJS) $(USER_OBJS) $(LIBS) 

matrix_10_tran30: $(OBJS) $(USER_OBJS) 
	g++ -c -w matrix_10_tran30.cpp 
	g++ -o matrix_10_tran30 matrix_10_tran30.o $(OBJS) $(USER_OBJS) $(LIBS) 

matrix_100_tran30: $(OBJS) $(USER_OBJS) 
	g++ -c -w matrix_100_tran30.cpp 
	g++ -o matrix_100_tran30 matrix_100_tran30.o $(OBJS) $(USER_OBJS) $(LIBS) 

matrix_1000_tran30: $(OBJS) $(USER_OBJS) 
	g++ -c -w matrix_1000_tran30.cpp 
	g++ -o matrix_1000_tran30 matrix_1000_tran30.o $(OBJS) $(USER_OBJS) $(LIBS) 

clean:
	-$(RM) *.o

#Clean-Everything
clean-all:
	-$(RM) $(OBJS)$(C++_DEPS)$(C_DEPS)$(CC_DEPS)$(CPP_DEPS)$(EXECUTABLES)$(CXX_DEPS)$(C_UPPER_DEPS) *.o test-code 

