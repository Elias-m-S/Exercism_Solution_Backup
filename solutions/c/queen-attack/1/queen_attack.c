#include "queen_attack.h"

// Hilfsfunktion
static int check_diagonal(const position_t queen_1, const position_t queen_2) {
    int row_diff = queen_1.row - queen_2.row;
    if (row_diff < 0) {
        row_diff = -row_diff;
    }

    int col_diff = queen_1.column - queen_2.column;
    if (col_diff < 0) {
        col_diff = -col_diff;
    }

    return (row_diff == col_diff);
}

attack_status_t can_attack(const position_t queen_1, const position_t queen_2) {
    if (queen_1.row > 7 || queen_1.column > 7 || queen_2.row > 7 || queen_2.column > 7) {
        return INVALID_POSITION;
    }

    if (queen_1.row == queen_2.row && queen_1.column == queen_2.column) {
        return INVALID_POSITION;
    }

    if (queen_1.row == queen_2.row || queen_1.column == queen_2.column) {
        return CAN_ATTACK;
    }

    if (check_diagonal(queen_1, queen_2)) {
        return CAN_ATTACK;
    }

    return CAN_NOT_ATTACK;
}
