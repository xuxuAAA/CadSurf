#include "stdafx.h"

#include "BSplineSurface.h"
#include "AxisSystem.h"
#include "MMath.h"
#include "GeomException.h"

CBSplineSurface::CBSplineSurface()
{
    cpMat[0][0] = CPoint3D(20, 0, 200);
    cpMat[0][1] = CPoint3D(0, 100, 150);
    cpMat[0][2] = CPoint3D(-130, 100, 50);
    cpMat[0][3] = CPoint3D(-250, 50, 0);
    cpMat[1][0] = CPoint3D(100, 100, 150);
    cpMat[1][1] = CPoint3D(30, 100, 100);
    cpMat[1][2] = CPoint3D(-40, 100, 50);
    cpMat[1][3] = CPoint3D(-110, 50, 0);
    cpMat[2][0] = CPoint3D(280, 90, 140);
    cpMat[2][1] = CPoint3D(110, 120, 80);
    cpMat[2][2] = CPoint3D(0, 130, 30);
    cpMat[2][3] = CPoint3D(-100, 150, -50);
    cpMat[3][0] = CPoint3D(350, 30, 150);
    cpMat[3][1] = CPoint3D(200, 150, 50);
    cpMat[3][2] = CPoint3D(50, 200, 0);
    cpMat[3][3] = CPoint3D(0, 100, -70);
}

CBSplineSurface::CBSplineSurface(const std::array<std::array<CPoint3D, 4>, 4> &newCpMatrix) : cpMat(newCpMatrix)
{
}

CPoint3D CBSplineSurface::PointAtPara(const double uPar, const double vPar)
{
    double u1 = uPar, v1 = vPar;
    double u2 = u1 * u1, v2 = v1 * v1;
    double u3 = u2 * u1, v3 = v2 * v1;

    std::array<double, 4> uMat, vMat;
    uMat[0] = (-u3 + 3 * u2 - 3 * u1 + 1) / 6;
    uMat[1] = (3 * u3 - 6 * u2 + 4) / 6;
    uMat[2] = (-3 * u3 + 3 * u2 + 3 * u1 + 1) / 6;
    uMat[3] = u3 / 6;
    vMat[0] = (-v3 + 3 * v2 - 3 * v1 + 1) / 6;
    vMat[1] = (3 * v3 - 6 * v2 + 4) / 6;
    vMat[2] = (-3 * v3 + 3 * v2 + 3 * v1 + 1) / 6;
    vMat[3] = v3 / 6;

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

bool CBSplineSurface::IsUClosed() const
{
    if (itsFirstUParameter == 0 && itsLastUParameter == 1)
        return true;
    return false;
}

bool CBSplineSurface::IsVClosed() const
{
    if (itsFirstVParameter == 0 && itsLastVParameter == 1)
        return true;
    return false;
}

CSurface* CBSplineSurface::Copy() const
{
    CBSplineSurface* R = new CBSplineSurface(cpMat);
    return R;
}

void CBSplineSurface::Translate(const COneAxis& Ax, const double& amt)
{
    CGeometry::Translate(Ax, amt);
}

void CBSplineSurface::Translate(double dx, double dy, double dz)
{
    itsLocation.Translate(dx, dy, dz);
}

void CBSplineSurface::Translate(const CVector3D& V)
{
    itsLocation.Translate(V);
}

void CBSplineSurface::Translate(const CPoint3D& P1, const CPoint3D& P2)
{
    itsLocation.Translate(P1, P2);
}

void CBSplineSurface::Rotate(const COneAxis& Ax, double ang)
{
    itsLocation.Rotate(Ax, ang);
}

void CBSplineSurface::Scale(const CPoint3D& P, double fact)
{
    itsLocation.Scale(P, fact);
}

void CBSplineSurface::Mirror(const CPoint3D& P)
{
    itsLocation.Mirror(P);
}

void CBSplineSurface::Mirror(const COneAxis& Ax)
{
    itsLocation.Mirror(Ax);
}

void CBSplineSurface::Mirror(const CPlane& Pln)
{
    itsLocation.Mirror(Pln);
}
