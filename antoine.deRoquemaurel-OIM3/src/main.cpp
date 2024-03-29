#include "raytracing.h"
#include <iostream>

/**
 * Le rôle de la fonction compute_direct_lighting() est de calculer la somme, pour chaque source de lumière de la scène, de l'éclairage
 * élémentaire dû à cette source. Cette somme est calculée en ajoutant à une couleur noire (triplet \b RGB [0, 0, 0], élément neutre de
 * l'addition des couleurs), la valeur de l'éclairage direct lié à chaque source de la scène. La fonction compute_direct_lighting()
 * utilise pour cela les fonctions des modules \ref SceneAPI (pour accéder à l'ensemble des sources lumineuses de la scène),
 * \ref RayAPI (pour calculer la visibilité entre un point et une source de lumière) et \ref LightAPI (pour calculer l'éclairage direct).
 */
Color compute_direct_lighting (Ray ray_, Isect isect_) {
    Color l = Color();
	int nbLights;
    Light *light_ = NULL;

    nbLights =  nb_lights();
    for(int i =0; i<nbLights ; i++){
        light_ = get_light(i);
        if(test_visibility(isect_, light_) == 1) {
            l = l + direct_lighting(ray_, isect_, light_);
        }
    }

    return l;

}

/**
 * La fonction trace_ray() renvoie une couleur obtenue par la somme de l'éclairage direct (couleur calculée par la fonction
 * compute_direct_lighting()) et des couleurs provenant des reflets et transparences éventuels aux points d'intersection.
 * Dans la première partie du TP, seul l'éclairage direct sera calculé. Dans la seconde partie, les reflets et transparences seront rajoutés.
 *
 * Pour la première étape, la fonction trace_ray() ne calculant que les rayons primaires, l'intersection
 * entre le rayon et la scène doit être calculée (fonction intersect_scene() du module \ref RayAPI).
 * S'il n'y a pas d'intersection, une couleur blanche (triplet RGB [1, 1, 1], élément neutre de la multiplication des couleurs)
 * devra être retournée.
 * S'il y a une intersection, la couleur retournée sera la couleur résultante de l'éclairage direct du point d'intersection par les
 * sources lumineuses de la scène et calculée par la fonction compute_direct_lighting() à écrire dans la suite.
 *
 * Pour la deuxième étape, à partir des fonctions définies dans le module \ref RayAPI et permettant d'accéder aux informations de
 * profondeur et d'importance sur le rayon, définir un cas d'arêt dela récursivité et renvoyer si ce cas est vérifié la couleur
 * résultante de l'éclairage direct. Si la récursivité n'est pas terminée, en utilisant les fonctions définies dans le module \ref LightAPI,
 * calculer la couleur réfléchie. Pour cela, il  faut tester si le matériau est réflechissant et, si c'est le cas, calculer le rayon
 * réfléchi et le coefficient de réflexion (une couleur). La couleur calculée en lançant le rayon réfléchi devra alors être multipliée par ce coefficient avant d'être ajoutée
 * à la couleur renvoyée par trace_ray().
 *
 * Pour la troisème étape et de façon très similaire à la réflexion, utiliser les fonctions définies dans le module \ref LightAPI pour calculer la couleur réfractée.
 * Pour cela, il  faut tester si le matériau est transparent et, si c'est le cas, calculer le rayon réfracté et le coefficient de
 * transparence (une couleur). La couleur calculée en lançant le rayon réfracté devra alors être multipliée par ce coefficient avant
 * d'être ajoutée à la couleur renvoyée par trace_ray().
 *
*/
Color trace_ray (Ray ray_) {
    Color lightning = init_color (0.f, 0.f, 0.f);
    Color rfl = init_color (0.f, 0.f, 0.f);
    Color rfr = init_color (0.f, 0.f, 0.f);

    Ray ray_rfl, ray_rfr;
    Isect isect_;

    if(ray_importance(ray_) > 0.0001) { // condition d'arrêt
        if(intersect_scene(&ray_, &isect_) == 1) {

            if(isect_has_reflection(isect_) == 1) {
                rfl = multiply_color_color(trace_ray(ray_rfl), reflect(ray_, isect_, &ray_rfl));
            }

            if(isect_has_refraction(isect_) == 1) {
                rfr = multiply_color_color(trace_ray(ray_rfr), refract(ray_, isect_, &ray_rfr));
            }

            lightning = compute_direct_lighting(ray_, isect_);
        } else {
            return black();
        }
    }

    return add_color_color(lightning, add_color_color(rfl, rfr));
}

/**
 * Le calcul d'une image de synthèse consiste à calculer une couleur pour tous les pixels d'une image en fonction
 * d'une modélisation d'un capteur virtuel.
 * Ce capteur est ici représenté par une Camera qui permet, à partir des coordonnées (x,y) d'un pixel d'une image,
 * de créer le rayon passant par ce pixel. La manière dont est créé ce rayon dépend de la Camera.
 * La scène étant crée avec une caméra par défaut de type \b pinhole, la fonction camera_ray()
 * devra être utilisée afin de créer le rayon primaire.
 * Ce rayon est ensuite tracé dans la scène (par la fonction trace_ray())
 * et la couleur calculée à l'aide de ce rayon doit être stockée sur le pixel (x,y).
*/
void compute_image () {
    Ray ray_;

    int x_res, y_res;
    get_image_resolution(&x_res, &y_res);

    for(float x=0; x<x_res; ++x) {
        for(float y=0; y<y_res; ++y) {
            ray_ = camera_ray(x,y);
            set_pixel_color(x,y,trace_ray(ray_));
        }
    }

}

/*
 * pendant vos test du devoir, pour limiter les temps de calcul avant d'avoir tout terminé, utiliser les valeurs suivantes :
 #define QUADRILLAGE "quadrillage-512.png"
 #define FOND "fond-512.png"
 
 */
// Pour bien voir les effets, préférez cette taille de texture si vous calculez une image HD (attention au temps de calcul qui explose à la question 3 mais redevient faible à la question 4)
//#define QUADRILLAGE "quadrillage-1024.png"
//#define FOND "fond-1024.png"

// Pour bien voir les effets, préférez cette taille de texture si vous calculez une image 1/2 HD
#define QUADRILLAGE "quadrillage-512.png"
#define FOND "fond-512.png"
#define MOSAIC "mosaic.png"

/**
 * \callgraph
 */
void make_textured_scene (int xsize, int ysize) {
	//camera
	set_camera (0.f, 2.f, -8.f,
				0.f, 0.f, 0.f,
				0.f, 1.f, 0.f,
				60.f, xsize, ysize);
    // source à utiliser pour les images test
//    add_light (0.f, 2.f, -8.f,
//               10.f, 10.f, 10.f);
	
    //sources à utiliser pour l'image finale
    // source frontale
    add_light (1.5, 3., -8.,
               0.5f, 0.5f, 0.5f);
//    // source latérale avant
    add_light (-6.9, 7.9, -7.,
               1.0, 1.0, 1.0);
//    // source arrière
    add_light (0.f, 3.5, 20,
                1.0f, 1.0f, 1.0f);


	
	// bottomplane
    Texture *bottomplanetexture = create_texture(QUADRILLAGE);
	bottomplanetexture->setScale(10.f, 10.f);
	bottomplanetexture->prefilter();
    Material * glossy = create_glossy_mat (0.1f, 0.05f, 0.1f, // kd
                                           .12f, .12f, .12f,  //ks
                                           3.f, 3.f, 3.f,  //kr
                                           400.f, 1.25f);
    Material * glass = create_glass_mat (1.f, 1.f, 1.f,
                                         1.f, 1.f, 1.f,
										 1.25f);
	Geometry * botomplane = create_plane (0.f, -1.f, 0.f,
										  0.f, 1.f, 0.f);
    add_object (botomplane, glossy); // try glass to see the difference
	
	
	// sideplanes and topplane
    Material * sideplanesmaterial = create_plastic_mat (0.5f, 0.5f, 0.5f,
                                                        0.0f, 0.0f, 0.0f,
														40.f);
	sideplanesmaterial->setTexture(bottomplanetexture);
	Geometry * leftplane = create_plane (-8.f, 0.f, 0.f,
										 1.f, 0.f, 0.f);
	Geometry * rightplane = create_plane (8.f, 0.f, 0.f,
										  -1.f, 0.f, 0.f);
    Geometry * topplane = create_plane (0.f, 8.f, 0.f,
                                        0.f, -1.f, 0.f);

    add_object (leftplane, sideplanesmaterial);
	add_object (rightplane, sideplanesmaterial);
	add_object (topplane, sideplanesmaterial);
	
	// backplane
    Material * backplanematerial = create_plastic_mat (0.5f, 0.5f, 0.5f,
                                                       0.0f, 0.0f, 0.0f,
                                                       10.f);
    Texture * backgroundtexture = create_texture(FOND);
	backgroundtexture->setScale(10.f, -10.f);
	backgroundtexture->prefilter();
	backplanematerial->setTexture(backgroundtexture);
	Geometry * backplane = create_plane (0.f, 9.f, 25.f,
										 0.f, 0.f, -1.f );
    backplane->settangent(Vector3D(1., 0., 0.));
	add_object (backplane, backplanematerial);
	
	// representative object

    Material * plastic_cylinder = create_glossy_mat (1, 1, 1,
                                               0.6f, 0.6f, 0.6f,
                                              0.5,0.5,0.5,/* 0.75f, 0.2f, 0.2f,*/
                                               25.f, 1.25f);
    Material * plastic_cone = create_glossy_mat (0.1f, 0.5f, 0.1f,
                                               /*0.8f, 0.8f, 0.8f,*/ 3., 3., 3.,
                                               0.1,0.1,0.1, /*0.2f, 0.75f, 0.2f,*/
                                               5.f, 1.25f);
    Material * plastic_sphere = create_glossy_mat (0.5f, 0.1f, 0.1f,
                                               0.3f, 0.2f, 0.2f,
                                               1.5, 1.5, 1.5, //0.75,0.75, 0.75, /*0.2f, 0.2f, 0.75f,*/
                                               500.f, 1.25f);
    Texture * gridtexture = create_texture(QUADRILLAGE);
    gridtexture->setScale(0.5f, 0.5f);
    gridtexture->prefilter();

    Texture * sphereTexture = create_texture(QUADRILLAGE);
    sphereTexture->setScale(1,1);
    sphereTexture->prefilter();

    Texture * gridtextureCylinder = create_texture(MOSAIC);
    gridtextureCylinder->setScale(0.5, 2);
    gridtextureCylinder->prefilter();

    plastic_cylinder->setTexture(gridtextureCylinder);
    plastic_cone->setTexture(gridtexture);
    plastic_sphere->setTexture(sphereTexture);
	Geometry * sphere = create_sphere (4.f, 1.f, 1.f, 2.f);
    Geometry * cylinder = create_cylinder(-4.5, -0.25, 2.5,
                                              0., 1., 0.,
                                              1.5, 1.5 );

    Geometry * cone = create_cone(1.0, -0.05, -3.0,
                                  -5.0, 1.25, 3,
                                  1.f );
    add_object (cylinder, plastic_cylinder);
    add_object (cone, plastic_cone);
    add_object (sphere, plastic_sphere);
}





/***************************************************/
/*******
 Fonctions données
 ******/
/**
 * \callgraph
 */
int main () {

// Creation scene test pour TP a comenter pour le devoir
//    make_default_scene(800, 600);

// creation scene test pour devoir numero 3 : a decomenter pour le devoir
// résolution de test : 1/2 HD --> attention au temps de calcul en cours de devoir si vous augmentez cette résolution (cf sujet)
    make_textured_scene(960, 540);
//     resolution HD
//    make_textured_scene(1920, 1080);

	compute_image();
	
	save_png ("monimage.png");

// Pour avoir l'image en haute dynamique : sauvegarde au format OpenEXR.
// Decommenter si vous voulez avoir une image plus précise
   save_image ("monimage.exr");

	return 0;
}
