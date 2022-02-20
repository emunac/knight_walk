#include <stdio.h>

struct point {
    int x;
    int y;
};

int in_grid(int x, int y){

    if(x < 0 || x > 7 || y < 0 || y > 7){
        return 0;
    }
    return 1;
}

struct point next_available_step(int x, int y, int grid[8][8]){

    int next_x[4] = { x-2, x+2, x-1, x+1 };
    int next_y[4] = { y-2, y+2, y-1, y+1 };
    int i,j;
    struct point ret = {-1, -1};

    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            if((i < 2 && j < 2) || i >= 2 && j >= 2){
                continue;
            }
            ret.x = next_x[i];
            ret.y = next_y[j];
            if(in_grid(ret.x, ret.y) && grid[ret.x][ret.y] != 1){
                return ret;
            }
        }
    }

    ret.x = -1;
    ret.y = -1;
    return ret;
}

int knight_walk(int x, int y){

    int count = 0;
    int grid[8][8] = { 0 };
    struct point next;

    x -= 1;
    y -= 1;
    if(!in_grid(x, y)){
        printf("Out of scope\n");
        return 0;
    }

    grid[x][y] = 1;

    while(count <= 64){
        next = next_available_step(x, y, grid);
        if(next.x == -1){ // No more available steps
            return count;
        }
        count ++;
        x = next.x;
        y = next.y;
        printf("Step %d: (%d, %d)\n", count, x, y);
        grid[x][y] = 1;
    }
}

int main() {
    int count;

    count = knight_walk(2,2);
    printf("%d", count);
    return 0;
}
