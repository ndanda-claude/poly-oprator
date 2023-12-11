#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


typedef struct Element {
    int degree;
    float coefficient;
    struct Element *suivant;
} Element;

typedef struct {
    Element *debut;
} Polynome;

void afficherPolynome(Polynome *poly) {
    Element *courant = poly->debut;
    while (courant != NULL) {
        printf("%.0fx^%d", courant->coefficient, courant->degree);
        courant = courant->suivant;
        if (courant != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

void ajouterTerme(Polynome *poly, int degree, float coefficient) {
    Element *newTerme = (Element *)malloc(sizeof(Element));
    newTerme->coefficient = coefficient;
    newTerme->degree = degree;
    newTerme->suivant = NULL;

    if (poly->debut == NULL) {
        poly->debut = newTerme;
    } else {
        Element *elemCourant = poly->debut;
        while (elemCourant->suivant != NULL) {
            elemCourant = elemCourant->suivant;
        }
        elemCourant->suivant = newTerme;
    }
}

Polynome multiplicationPolynomeConstante(const Polynome *poly, float constante) {
    Polynome result;
    result.debut = NULL;

    Element *courant = poly->debut;

    while (courant != NULL) {
        ajouterTerme(&result, courant->degree, courant->coefficient * constante);
        courant = courant->suivant;
    }

    return result;
}

Polynome multiplicationPolynomeMonome(const Polynome *poly, int monodegree, float monocoef) {
    Polynome result;
    result.debut = NULL;

    Element *courant = poly->debut;

    while (courant != NULL) {
        ajouterTerme(&result, courant->degree + monodegree, courant->coefficient * monocoef);
        courant = courant->suivant;
    }

    return result;
}

Polynome addition2Polynome(const Polynome *poly1, const Polynome *poly2) {
    Polynome result;
    result.debut = NULL;

    Element *courant1 = poly1->debut;
    Element *courant2 = poly2->debut;

    while (courant1 != NULL || courant2 != NULL) {
        int degree;
        float coefficient;

        if (courant1 != NULL && courant2 != NULL) {
            if (courant1->degree == courant2->degree) {
                degree = courant1->degree;
                coefficient = courant1->coefficient + courant2->coefficient;
                courant1 = courant1->suivant;
                courant2 = courant2->suivant;
            } else if (courant1->degree > courant2->degree) {
                degree = courant1->degree;
                coefficient = courant1->coefficient;
                courant1 = courant1->suivant;
            } else {
                degree = courant2->degree;
                coefficient = courant2->coefficient;
                courant2 = courant2->suivant;
            }
        } else if (courant1 != NULL) {
            degree = courant1->degree;
            coefficient = courant1->coefficient;
            courant1 = courant1->suivant;
        } else {
            degree = courant2->degree;
            coefficient = courant2->coefficient;
            courant2 = courant2->suivant;
        }

        ajouterTerme(&result, degree, coefficient);
    }

    return result;
}






Polynome subtraction2Polynome(const Polynome *poly1, const Polynome *poly2) {
    Polynome result;
    result.debut = NULL;

    Element *courant1 = poly1->debut;
    Element *courant2 = poly2->debut;

    while (courant1 != NULL || courant2 != NULL) {
        int degree;
        float coefficient;

        if (courant1 != NULL && courant2 != NULL) {
            if (courant1->degree == courant2->degree) {
                degree = courant1->degree;
                coefficient = courant1->coefficient - courant2->coefficient;
                courant1 = courant1->suivant;
                courant2 = courant2->suivant;
            } else if (courant1->degree > courant2->degree) {
                degree = courant1->degree;
                coefficient = courant1->coefficient;
                courant1 = courant1->suivant;
            } else {
                degree = courant2->degree;
                coefficient = -courant2->coefficient; // Subtracting coefficients
                courant2 = courant2->suivant;
            }
        } else if (courant1 != NULL) {
            degree = courant1->degree;
            coefficient = courant1->coefficient;
            courant1 = courant1->suivant;
        } else {
            degree = courant2->degree;
            coefficient = -courant2->coefficient; // Subtracting coefficients
            courant2 = courant2->suivant;
        }

        ajouterTerme(&result, degree, coefficient);
    }

    return result;
}






void ajouterPolynome(Polynome *poly1, const Polynome *poly2) {
    Element *courant = poly2->debut;

    while (courant != NULL) {
        ajouterTerme(poly1, courant->degree, courant->coefficient);
        courant = courant->suivant;
    }
}

void afficherMenu() {

printf("\n");
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  MENU PRINCIPALE \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");
printf("\n");
printf("\xDB\xDB\xDB\xDB\xB2 1. Ajouter un terme au polyn�me\n");

printf("\xDB\xDB\xDB\xDB\xB2 2. Afficher le polyn�me\n");

printf("\xDB\xDB\xDB\xDB\xB2 3. Multiplier par une constante\n");

printf("\xDB\xDB\xDB\xDB\xB2 4. Multiplier un polyn�me par un mon�me\n");

printf("\xDB\xDB\xDB\xDB\xB2 5. Additionner deux polyn�mes\n");

printf("\xDB\xDB\xDB\xDB\xB2 6. soustraire deux polyn�mes\n");

printf("\xDB\xDB\xDB\xDB\xB2 7. Modifier le premier polyn�me\n");

printf("\xDB\xDB\xDB\xDB\xB2 8. Quitter\n");

printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");

printf("Enter your choice:");
printf("\n");


}

int main() {


 	printf("\t\t*************************************************\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*       -----------------------------           *\n");
	printf("\t\t*        WELCOME TO POLY-OPERATOR               *\n");
	printf("\t\t*       -----------------------------           *\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*           FOMO NDANDA CLAUDE                  *\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*   github.com/ndanda-claude/poly-oprator       *\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*     CONTACT Me:+237 694699644,+237 681297063  *\n");
	printf("\t\t*************************************************\n\n\n");

    Polynome *poly = (Polynome *)malloc(sizeof(Polynome));
    poly->debut = NULL;

    int degree;
    printf("Entrer le degr� du polyn�me : ");
    scanf("%d", &degree);

    printf("Entrer les coefficients du polyn�me :\n");
    for (int i = degree; i >= 0; i--) {
        float coefficient;
        printf("Coefficient de x^%d : ", i);
        scanf("%f", &coefficient);
        ajouterTerme(poly, i, coefficient);
    }

    int choix;
    float constante;
    int monodegree;
    float monocoef;
    Polynome poly2;

    do {
        afficherMenu();
        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:

                printf("Entrer le degr� du nouveau polyn�me : ");
                scanf("%d", &degree);

                printf("Entrer les coefficients du nouveau polyn�me :\n");
                float coefficient;
                scanf("%f", &coefficient);
                ajouterTerme(poly, degree, coefficient);
                break;

            case 2:

                printf("Polynome : ");
                afficherPolynome(poly);
                break;

            case 3:

                printf("Entrez la constante : ");
                scanf("%f", &constante);
                Polynome resultatMultiplication = multiplicationPolynomeConstante(poly, constante);
                printf("R�sultat de la multiplication par constante : ");
                afficherPolynome(&resultatMultiplication);
                break;
            case 4:

                printf("Entrer le degr� du mon�me : ");
                scanf("%d", &monodegree);
                printf("Entrer le coefficient du mon�me : ");
                scanf("%f", &monocoef);
                Polynome resultatMultiplicationMonome = multiplicationPolynomeMonome(poly, monodegree, monocoef);
                printf("R�sultat de la multiplication par mon�me : ");
                afficherPolynome(&resultatMultiplicationMonome);
                break;
            case 5:

                poly2.debut = NULL;
                printf("Entrer le degr� du deuxi�me polyn�me : ");
                scanf("%d", &degree);

                printf("Entrer les coefficients du deuxi�me polyn�me :\n");
                for (int i = degree; i >= 0; i--) {
                    float coefficient;
                    printf("Coefficient de x^%d : ", i);
                    scanf("%f", &coefficient);
                    ajouterTerme(&poly2, i, coefficient);
                }

                Polynome resultatAddition = addition2Polynome(poly, &poly2);

                printf("R�sultat de l'addition des polyn�mes : ");
                afficherPolynome(&resultatAddition);
                break;
            case 6:


                poly2.debut = NULL;
                printf("Entrer le degr� du deuxi�me polyn�me : ");
                scanf("%d", &degree);

                printf("Entrer les coefficients du deuxi�me polyn�me :\n");
                for (int i = degree; i >= 0; i--) {
                    float coefficient;
                    printf("Coefficient de x^%d : ", i);
                    scanf("%f", &coefficient);
                    ajouterTerme(&poly2, i, coefficient);
                }

                Polynome resultatSoustraction = subtraction2Polynome(poly, &poly2);

                printf("R�sultat de la soustraction des polyn�mes : ");
                afficherPolynome(&resultatSoustraction);
                break;

            case 7:

                printf("Entrer le nouveau degr� du polyn�me : ");
                scanf("%d", &degree);


                Element *courant = poly->debut;
                while (courant != NULL) {
                    Element *suivant = courant->suivant;
                    free(courant);
                    courant = suivant;
                }


                poly->debut = NULL;


                printf("Entrer les nouveaux coefficients du polyn�me :\n");
                for (int i = degree; i >= 0; i--) {
                    float coefficient;
                    printf("Coefficient de x^%d : ", i);
                    scanf("%f", &coefficient);
                    ajouterTerme(poly, i, coefficient);
                }
                break;


            case 8:

                break;
            default:
                printf("Choix invalide. Veuillez r�essayer.\n");
        }
    } while (choix != 8);


    Element *courant = poly->debut;
    while (courant != NULL) {
        Element *suivant = courant->suivant;
        free(courant);
        courant = suivant;
    }
    free(poly);

    return 0;
}
