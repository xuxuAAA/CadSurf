#ifndef _BEZIERSURFACE_H
#define _BEZIERSURFACE_H

#include <array>
#include <tuple>

#include "VKGeom.h"

#include "BasicSurface.h"

class VKGEOM_API CBezierSurface : public CBasicSurface
{
public:
	CBezierSurface();
	CBezierSurface(const std::array<std::array<CPoint3D, 4>, 4>&);
	inline void SetCpMatrix(const std::array<std::array<CPoint3D, 4>, 4>& newCpMatrix) { cpMat = newCpMatrix; }
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

#endif /* _BEZIERSURFACE_H */
