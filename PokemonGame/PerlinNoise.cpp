#include "PerlinNoise.h"


void PerlinNoise::populate()
{

    // Initialization {{{
    const int SEED = 7;
    srand(SEED);
    Vector2 lattice[LATTICE_X][LATTICE_Y];
    Vector2 tempVector;
    for (int latticeY = 0; latticeY < LATTICE_Y; latticeY++) {
        for (int latticeX = 0; latticeX < LATTICE_X; latticeX++) {
            tempVector.x = getRand();
            tempVector.y = getRand();
            tempVector.normalize();
            lattice[latticeX][latticeY] = tempVector;
        }
    }

    // }}}
    // Main Algorithm {{{
    Point topLeft;
    Point bottomRight;
    Vector2 d[2][2];
    double g[2][2];
	bool debug = false;
    int bX = 1;
    int bY = 1;
    for (int pY = 0; pY < PIXEL_Y; pY++) {
        for (int pX = 0; pX < PIXEL_X; pX++) {

            topLeft.x = (pX / CELL_SIZE) * (CELL_SIZE - 1);
            topLeft.y = (pY / CELL_SIZE) * (CELL_SIZE - 1);
            bottomRight.x = topLeft.x + CELL_SIZE -1;
            bottomRight.y = topLeft.y + CELL_SIZE - 1;

            d[0][0].x = pX - topLeft.x;
            d[0][0].y = pY - topLeft.y;

            d[1][0].x = pX - bottomRight.x;
            d[1][0].y = pY - topLeft.y;

            d[0][1].x = pX - topLeft.x;
            d[0][1].y = pY - bottomRight.y;

            d[1][1].x = pX - bottomRight.x;
            d[1][1].y = pY - bottomRight.y;



            for (int gY = 0; gY < 2; gY++) {
                for (int gX = 0; gX < 2; gX++) {
                    Vector2 latticeVector = lattice [(topLeft.x / CELL_SIZE) + gX]
                                                    [(topLeft.y / CELL_SIZE) + gY];
                    g[gX][gY] = d[gX][gY].dotProduct(latticeVector);
                }
            }

            double fracX = ((double) (pX - topLeft.x)) / ((double) CELL_SIZE - 1);
            double r1 = lerp(g[0][0], g[1][0], fracX);
            double r2 = lerp(g[0][1], g[1][1], fracX);

            double fracY = ((double) (pY - topLeft.y)) / ((double) CELL_SIZE - 1);
            double retVal = lerp(r1, r2, fracY);

            // Debug Arrays {{{

            if (debug && pX == bX && pY == bY) {
                printf("topLeft:");
                topLeft.display();
                printf("\n");

                printf("bottomRight:");
                bottomRight.display();
                printf("\n");

                for (int dY = 0; dY < 2; dY++) {
                    for (int dX = 0; dX < 2; dX++) {
                        printf("d[%d][%d]:", dX, dY);
                        d[dX][dY].display();
                        printf("\t");
                    }
                    printf("\n");
                }
                printf("\n");

                for (int gY = 0; gY < 2; gY++) {
                    for (int gX = 0; gX < 2; gX++) {
                        printf("g[%d][%d]: %.3f\t", gX, gY, g[gX][gY]);
                    }
                    printf("\n");
                }
                printf("\n");

                for (int latticeY = 0; latticeY < LATTICE_Y; latticeY++) {
                    for (int latticeX = 0; latticeX < LATTICE_X; latticeX++) {
                        printf("lattice[%d][%d]:", latticeX, latticeY);
                        lattice[latticeX][latticeY].display();
                        printf("\t");
                    }
                    printf("\n");
                }
                printf("\n");
                printf("r1:%.3f\n", r1);
                printf("r2:%.3f\n", r2);
                printf("retVal:%.3f\n", retVal);
            }
            // }}}
			pixels[pX][pY] = retVal;
        }

    }

    // }}}

	printf("Results\n");
	for (int j = 0; j < PIXEL_Y; j++) {
		for (int i = 0; i < PIXEL_X; i++) {
			printf("%.3f\t" , pixels[i][j]);
		}
		printf("\n");
	}
    getchar();
}


PerlinNoise::PerlinNoise()
{
}


PerlinNoise::~PerlinNoise()
{
}



double PerlinNoise::lerp(double a, double b, double t) {
    return a + (b - a) * t;
}

double PerlinNoise::getRand() {
    int x = rand();
    double ret = (double) (x % 100);
    return ret;
}

