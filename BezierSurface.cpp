#include "stdafx.h"

#include "BezierSurface.h"
#include "AxisSystem.h"
#include "MMath.h"
#include "GeomException.h"

CBezierSurface::CBezierSurface(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3,
    double x4, double y4, double z4, double x5, double y5, double z5, double x6, double y6, double z6, double x7, double y7, double z7,
    double x8, double y8, double z8, double x9, double y9, double z9, double x10, double y10, double z10, double x11, double y11, double z11,
    double x12, double y12, double z12, double x13, double y13, double z13, double x14, double y14, double z14, double x15, double y15, double z15,
    double x16, double y16, double z16)
{
    cpMat[0][0] = CPoint3D(x1, y1, z1);
    cpMat[0][1] = CPoint3D(x2, y2, z2);
    cpMat[0][2] = CPoint3D(x3, y3, z3);
    cpMat[0][3] = CPoint3D(x4, y4, z4);
    cpMat[1][0] = CPoint3D(x5, y5, z5);
    cpMat[1][1] = CPoint3D(x6, y6, z6);
    cpMat[1][2] = CPoint3D(x7, y7, z7);
    cpMat[1][3] = CPoint3D(x8, y8, z8);
    cpMat[2][0] = CPoint3D(x9, y9, z9);
    cpMat[2][1] = CPoint3D(x10, y10, z10);
    cpMat[2][2] = CPoint3D(x11, y11, z11);
    cpMat[2][3] = CPoint3D(x12, y12, z12);
    cpMat[3][0] = CPoint3D(x13, y13, z13);
    cpMat[3][1] = CPoint3D(x14, y14, z14);
    cpMat[3][2] = CPoint3D(x15, y15, z15);
    cpMat[3][3] = CPoint3D(x16, y16, z16);
}
 
CBezierSurface::CBezierSurface(const std::array<std::array<CPoint3D, 4>, 4>& newCpMatrix) : cpMat(newCpMatrix)
{
}

CPoint3D CBezierSurface::PointAtPara(const double uPar, const double vPar)
{
    double u1 = uPar, v1 = vPar;
    double u2 = u1 * u1, v2 = v1 * v1;
    double u3 = u2 * u1, v3 = v2 * v1;

    std::array<double, 4> uMat, vMat;
    uMat[0] = -u3 + 3 * u2 - 3 * u1 + 1;
    uMat[1] = 3 * u3 - 6 * u2 + 3 * u1;
    uMat[2] = -3 * u3 + 3 * u2;
    uMat[3] = u3;
    vMat[0] = -v3 + 3 * v2 - 3 * v1 + 1;
    vMat[1] = 3 * v3 - 6 * v2 + 3 * v1;
    vMat[2] = -3 * v3 + 3 * v2;
    vMat[3] = v3;

    CPoint3D result(0, 0, 0);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            result += cpMat[i][j] * uMat[i] * vMat[j];
        }
    }
    return result;
}

bool CBezierSurface::IsUClosed() const
{
    if (itsFirstUParameter == 0 && itsLastUParameter == 1)
        return true;
    return false;
}

bool CBezierSurface::IsVClosed() const
{
    if (itsFirstVParameter == 0 && itsLastVParameter == 1)
        return true;
    return false;
}

CSurface* CBezierSurface::Copy() const
{
    CBezierSurface* R = new CBezierSurface(cpMat);
    return R;
}

void CBezierSurface::Translate(const COneAxis& Ax, const double& amt)
{
    CGeometry::Translate(Ax, amt);
}

void CBezierSurface::Translate(double dx, double dy, double dz)
{
    itsLocation.Translate(dx, dy, dz);
}

void CBezierSurface::Translate(const CVector3D& V)
{
    itsLocation.Translate(V);
}

void CBezierSurface::Translate(const CPoint3D& P1, const CPoint3D& P2)
{
    itsLocation.Translate(P1, P2);
}

void CBezierSurface::Rotate(const COneAxis& Ax, double ang)
{
    itsLocation.Rotate(Ax, ang);
}

void CBezierSurface::Scale(const CPoint3D& P, double fact)
{
    itsLocation.Scale(P, fact);
}

void CBezierSurface::Mirror(const CPoint3D& P)
{
    itsLocation.Mirror(P);
}

void CBezierSurface::Mirror(const COneAxis& Ax)
{
    itsLocation.Mirror(Ax);
}

void CBezierSurface::Mirror(const CPlane& Pln)
{
    itsLocation.Mirror(Pln);
}
