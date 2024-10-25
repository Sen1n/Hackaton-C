1. possible way how to check if polygone is convex:

to be brief ----- find the vector product of their sides and check whether they have the same sign.

the Gift-Wrapping Algorithm... that's a good answer when you have a set of points w/o any particular boundary and need to find the convex hull.

In contrast, consider the case where the polygon is not self-intersecting, and it consists of a set of points in a list where the consecutive points form the boundary. 
In this case it is much easier to figure out whether a polygon is convex or not (and you don't have to calculate any angles, either):

For each consecutive pair of edges of the polygon (each triplet of points), compute the z-component of the cross product of the vectors 
defined by the edges pointing towards the points in increasing order. Take the cross product of these vectors:

 given p[k], p[k+1], p[k+2] each with coordinates x, y:
 dx1 = x[k+1]-x[k]
 dy1 = y[k+1]-y[k]
 dx2 = x[k+2]-x[k+1]
 dy2 = y[k+2]-y[k+1]
 zcrossproduct = dx1*dy2 - dy1*dx2
The polygon is convex if the z-components of the cross products are either all positive or all negative. Otherwise the polygon is nonconvex.

If there are N points, make sure you calculate N cross products, e.g. be sure to use the triplets (p[N-2],p[N-1],p[0]) and (p[N-1],p[0],p[1]).




