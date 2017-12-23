/*
- fonction qui renvoie la position 3D du pixel en fonction de sa position 2D "Position getPosition(int x, int y)"
- pour chaque pixel tracer un rayon issue de la camera: Ray drawRayFromCamera(Position pixelPos)
si intersectionWithSphere
  tracer un rayon issue du point d'intersection Ray drawRayFromIntersection(Position sourcePos)
  si intersectionWithSource
    pixel non eclaire (noir ?)
  sinon
    pixel eclaire
sinon
  couleur background


Ray drawRayFromCamera(int x, int y)
creer un rayon issue de la cam allant vers le pixel

boolean intersectionWithSphere(Sphere s)
renvoie true si le rayon intersecte la Sphere

boolean intersectionWithSource(Source s)
renvoie true si le rayon intersecte la source)

Ray getTangent(Sphere s, Position intersection)
renvoie la tangente de la sphere au point d'intersection

getPerpendicular(Sphere s, Ray tangent)
renvoie la perpendiculaire à la tangente

int getAlpha(Ray tangent, Ray perpendicular)
revoie l'angle entre la perpendiculaire à la tangente et le rayon vers la source

Ray drawRayFromIntersection(Position source)
renvoie le rayon entre issue du point d'intersection allant vers la source
*/

/* Scene
pour chaque pixel de l'ecran calculer sa couleur et l'écrire dans le fichier ppm
*/
