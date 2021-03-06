/* 
 * Copyright (c) 2013 Opposite Renderer
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

#pragma once
#include "Material.h"
#include "Math/Vector3.h"
#include "Util/ptxpath.h"

class Glass : public Material
{
private:
    float indexOfRefraction;
    Vector3 Ks;
    static bool m_optixMaterialIsCreated;
    static optix::Material m_optixMaterial;
public:
    Glass(float indexOfRefraction, const Vector3 & Ks, int class_id, int instance_id);
    virtual optix::Material getOptixMaterial(optix::Context & context);
    virtual void registerGeometryInstanceValues(optix::GeometryInstance & instance);
    virtual std::string materialType() { return "Glass"; };
};
