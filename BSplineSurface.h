#ifndef _BSPLINESURFACE_H
#define _BSPLINESURFACE_H

#include <array>
#include <tuple>

#include "VKGeom.h"

#include "BasicSurface.h"

class VKGEOM_API CBSplineSurface : public CBasicSurface
{
public:
	CBSplineSurface(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3,
		double x4, double y4, double z4, double x5, double y5, double z5, double x6, double y6, double z6, double x7, double y7, double z7,
		double x8, double y8, double z8, double x9, double y9, double z9, double x10, double y10, double z10, double x11, double y11, double z11,
		double x12, double y12, double z12, double x13, double y13, double z13, double x14, double y14, double z14, double x15, double y15, double z15,
		double x16, double y16, double z16);
	CBSplineSurface(const std::array<std::array<CPoint3D, 4>, 4> &);
	inline void SetCpMatrix(const std::array<std::array<CPoint3D, 4>, 4> &newCpMatrix) { cpMat = newCpMatrix; }
	inline std::array<std::array<CPoint3D, 4>, 4> GetCpMatrix() const { return cpMat; }
	virtual CPoint3D PointAtPara(const double uPar, const double vPar);
	inline virtual double FirstUParameter() const { return 0; }
	inline virtual double LastUParameter() const { return 1; }
	inline virtual double FirstVParameter() const { return 0; }
	inline virtual double LastVParameter() const { return 1; }
	virtual bool IsUClosed() const;
	virtual bool IsVClosed() const;
	virtual CSurface* Copy() const;
	virtual void Translate(const COneAxis&, const double&);
	virtual void Translate(double dx, double dy, double dz);
	virtual void Translate(const CVector3D&);
	virtual void Translate(const CPoint3D&, const CPoint3D&);
	virtual void Rotate(const COneAxis&, double);
	virtual void Scale(const CPoint3D&, double);
	virtual void Mirror(const CPoint3D&);
	virtual void Mirror(const COneAxis&);
	virtual void Mirror(const CPlane&);
private:
	std::array<std::array<CPoint3D, 4>, 4> cpMat;
};

#endif /* _BSPLINESURFACE_H */
