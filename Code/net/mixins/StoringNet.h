// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_NET_MIXINS_STORINGNET_H
#define HEMELB_NET_MIXINS_STORINGNET_H
#include "net/BaseNet.h"
#include "log/Logger.h"
#include "net/ProcComms.h"
namespace hemelb
{
  namespace net
  {
    class StoringNet : public virtual BaseNet
    {
      public:

        void RequestSendImpl(void* pointer, int count, proc_t rank, MPI_Datatype type);
        void RequestReceiveImpl(void* pointer, int count, proc_t rank, MPI_Datatype type);

        void RequestGatherVSendImpl(void* buffer, int count, proc_t toRank, MPI_Datatype type);
        void RequestGatherReceiveImpl(void* buffer, MPI_Datatype type);

        void RequestGatherSendImpl(void* buffer, proc_t toRank, MPI_Datatype type);
        void RequestGatherVReceiveImpl(void* buffer, int * displacements, int *counts, MPI_Datatype type);

        virtual void RequestAllToAllReceiveImpl(void * buffer, int count, MPI_Datatype type);
        virtual void RequestAllToAllSendImpl(void * buffer, int count, MPI_Datatype type);

      protected:
        /**
         * Struct representing all that's needed to successfully communicate with another processor.
         */

        std::map<proc_t, ProcComms> sendProcessorComms;
        std::map<proc_t, ProcComms> receiveProcessorComms;

        std::map<proc_t, ProcComms> gatherVSendProcessorComms;
        GatherVReceiveProcComms gatherVReceiveProcessorComms;

        std::map<proc_t, GatherProcComms> gatherSendProcessorComms;
        GatherProcComms gatherReceiveProcessorComms;

        AllToAllProcComms allToAllReceiveProcComms;
        AllToAllProcComms allToAllSendProcComms;

    };
  }
}
#endif
