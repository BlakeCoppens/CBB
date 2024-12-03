#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <MovieClass.h>

using namespace std;

class BSTNode {
public:
    Movie movie;
    BSTNode* left;
    BSTNode* right;

    // Constructor
    BSTNode(const Movie& movie) : movie(movie), left(nullptr), right(nullptr) {}
};

class MovieBST {
private:
    BSTNode* root;

    // Helper function to insert a movie into the BST
    BSTNode* insert(BSTNode* node, const Movie& movie) {
        if (node == nullptr) return new BSTNode(movie);

        if (movie.getRating() < node->movie.getRating()) node->left = insert(node->left, movie);
        else node->right = insert(node->right, movie);

        return node;
    }

    // Helper function for in-order traversal
    void inOrderTraversal(BSTNode* node, vector<Movie>& sortedMovies) const {
        if (node == nullptr) return;
        inOrderTraversal(node->left, sortedMovies);
        sortedMovies.push_back(node->movie);
        inOrderTraversal(node->right, sortedMovies);
    }

    // Helper function to delete the BST
    void deleteTree(BSTNode* node) {
        if (node == nullptr) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

public:

    MovieBST() : root(nullptr) {}
    ~MovieBST() { deleteTree(root); }

    // Method to insert a movie into the BST
    void insert(const Movie& movie) { root = insert(root, movie); }

    // Method to get movies sorted by rating
    vector<Movie> getSortedMovies() const {
        vector<Movie> sortedMovies;
        inOrderTraversal(root, sortedMovies);
        return sortedMovies;
    }
};
