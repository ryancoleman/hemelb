// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_VIS_RAYTRACER_CLUSTERNORMAL_H
#define HEMELB_VIS_RAYTRACER_CLUSTERNORMAL_H

#include "vis/rayTracer/Cluster.h"
#include "vis/rayTracer/SiteData.h"

namespace hemelb
{
  namespace vis
  {
    namespace raytracer
    {
      class ClusterNormal : public Cluster<ClusterNormal>
      {
        public:
          ClusterNormal(unsigned short xBlockCount,
                        unsigned short yBlockCount,
                        unsigned short zBlockCount,
                        const util::Vector3D<float>& minimalSite,
                        const util::Vector3D<float>& maximalSite,
                        const util::Vector3D<float>& minimalSiteOnMinimalBlock,
                        const util::Vector3D<site_t>& minimalBlock);

          const util::Vector3D<double>* DoGetWallData(site_t iBlockNumber, site_t iSiteNumber) const;

          void DoSetWallData(site_t iBlockNumber, site_t iSiteNumber, const util::Vector3D<double>& iData);
      };

    }
  }
}

#endif // HEMELB_VIS_RAYTRACER_CLUSTERNORMAL_H
