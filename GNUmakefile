#=========================================================================================
# GNUmakefile for GCC 3.01.                                                               
# Copyright 2001 MillenniumIT Software.                                                   
#=========================================================================================

# The options in this file will depend on the options selected during its creation.       



#-----------------------------------------------------------------------------------------
# CPP compile/link flags.                                                                 
#-----------------------------------------------------------------------------------------
include $(MAKEFILE_HEADER)

CCFLAGS=	$(FULLWARN) $(DEBUG)
# CCFLAGS=	$(FULLWARN) $(FLOWANALYSIS) $(OPTIMIZE)


# GNU C++ compiler...                                                                     
CC=	g++ # GNU C++ compiler
RM=	rm  # for clean up... 



#-----------------------------------------------------------------------------------------
# Libraries & include dirs                                                                
#-----------------------------------------------------------------------------------------

# Telco libs & include files.                                                             
TELCO_INC_PATH = -I$(DEV_INC)
TELCO_LIB_PATH = -L$(DEV_LIB) -L$(DEV_SO)


# Oracle OCI libs & include files.                                                        
include /development/include/Products/ccbs2/Oracle.GNUmakefile

# C++ compile flags, lib directory & libraries.                                           
CXXFLAGS = $(TELCO_INC_PATH) $(OCI_INC_PATH) $(RV_INC_PATH) $(CCFLAGS)
LIB_PATH = $(TELCO_LIB_PATH) $(OCI_LIB_PATH) $(RV_LIB_PATH)
LIBS     = $(OCI_LIBS) /development/lib/Products/ccbs2/OCICPP.o 
BILLPROC_LIB = ../../billing/BillProcess.Compilable/BillProcess.o -lmitproc -lmitcipher -lmitcfg -lmiterr -lmitobj $(DEV_LIB)/ObjectInit.o $(RV_LIBS)
#BILLPROC_LIB = -lmitproc -lmitcipher -lmitcfg -lmiterr  $(RV_LIBS)


# build calls                                                                             
build: r4_mediation_engine

# the object files that need to be built...                                                
BUILD_OBJS = call_partner_networks.o cdr_buffer.o cdr_decode.o cdr_file_locations.o cdr_file_statistics.o cdr_files.o cdr_unpack.o code_decode.o db.o dev_history.o dyn_7_udr.o identity.o mediation.o rated_cdr.o reng_date_time.o token.o vm_call_partners.o

# the actual build calls...                                                                
r4_mediation_engine: $(BUILD_OBJS)
	$(CXX) $(LIB_PATH) -o$@ $(BUILD_OBJS) $(LIBS) $(BILLPROC_LIB)


