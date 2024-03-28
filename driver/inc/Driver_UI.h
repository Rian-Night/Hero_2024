#ifndef __DRIVER_UI_H
#define __DRIVER_UI_H

#include "protocol.h"
#include "stm32f4xx.h"
#include "Driver_Protocol.h"
#include "config.h"

#define CAT(x, y) x##y

/** @brief 发送用图形基本结构
 *  @details
 *  分为  单图形
 *        双图形
 *        五图形
 *        七图形
 *  注：制作图形时请注意分组，单次发送有图形数限制（上述）
 *      为避免需要设定某一数量发送的轮询更新
 *      务必动态、静态分离， 静态只在首次更新发送，
 *      动态需反复调用数据发送
 *
 *  此处并没有把删除图层结构体加入进来， 由于该结构体较为简单，
 *  直接在task调用protocol中相关的结构体即可。
 */

typedef struct {
    uint8_t  figure_name[3];
    uint32_t operate_tpye : 3;
    uint32_t figure_tpye : 3;
    uint32_t layer : 4;
    uint32_t color : 4;
    uint32_t details_a : 9;
    uint32_t details_b : 9;
    uint32_t width : 10;
    uint32_t start_x : 11;
    uint32_t start_y : 11;
    uint32_t details_c : 10;
    uint32_t details_d : 11;
    uint32_t details_e : 11;
} interaction_figure_t;

typedef union {
    struct {
        interaction_figure_t interaction_figure[1];
    };
    struct {
        uint8_t data[15];
    };
} interaction_figure_1_t;

typedef union {
    struct {
        interaction_figure_t interaction_figure[2];
    };
    struct {
        uint8_t data[30];
    };
} interaction_figure_2_t;

typedef union {
    struct {
        interaction_figure_t interaction_figure[5];
    };
    struct {
        uint8_t data[75];
    };
} interaction_figure_5_t;

typedef union {
    struct {
        interaction_figure_t interaction_figure[7];
    };
    struct {
        uint8_t data[105];
    };
} interaction_figure_7_t;

typedef union {
    struct {
        interaction_figure_t interaction_figure;
        uint8_t              data[30];
    };
    struct {
        uint8_t data[45]
    };
} ext_client_custom_character_t;

/**
 * @brief 图形基本类型
 * @details
 * 几种基本图形类型
 * 每个参数具体要求
 *
 */

typedef union {
    struct {
        uint8_t  figure_name[3];
        uint32_t operate_tpyel : 3;
        uint32_t figure_tpye : 3;
        uint32_t layer : 4;
        uint32_t color : 4;
        uint32_t details_a : 9;
        uint32_t details_b : 9;
        uint32_t width : 10;
        uint32_t start_x : 11;
        uint32_t start_y : 11;
        uint32_t details_c : 10;
        uint32_t end_x : 11;
        uint32_t end_y : 11;
    };
    struct {
        uint8_t data[15];
    };
} UI_line_t;

typedef union {
    struct {
        uint8_t  figure_name[3];
        uint32_t operate_tpyel : 3;
        uint32_t figure_tpye : 3;
        uint32_t layer : 4;
        uint32_t color : 4;
        uint32_t details_a : 9;
        uint32_t details_b : 9;
        uint32_t width : 10;
        uint32_t start_x : 11;
        uint32_t start_y : 11;
        uint32_t details_c : 10;
        uint32_t opposite_x : 11;
        uint32_t opposite_y : 11;
    };
    struct {
        uint8_t data[15];
    };
} UI_rectangle_t;

typedef union {
    struct {
        uint8_t  figure_name[3];
        uint32_t operate_tpyel : 3;
        uint32_t figure_tpye : 3;
        uint32_t layer : 4;
        uint32_t color : 4;
        uint32_t details_a : 9;
        uint32_t details_b : 9;
        uint32_t width : 10;
        uint32_t start_x : 11;
        uint32_t start_y : 11;
        uint32_t radius : 10;
        uint32_t details_d : 11;
        uint32_t details_e : 11;
    };
    struct {
        uint8_t data[15];
    };
} UI_circle_t;

typedef union {
    struct {
        uint8_t  figure_name[3];
        uint32_t operate_tpyel : 3;
        uint32_t figure_tpye : 3;
        uint32_t layer : 4;
        uint32_t color : 4;
        uint32_t details_a : 9;
        uint32_t details_b : 9;
        uint32_t width : 10;
        uint32_t start_x : 11;
        uint32_t start_y : 11;
        uint32_t details_c : 10;
        uint32_t length_semiaxis_x : 11;
        uint32_t length_semiaxis_y : 11;
    };
    struct {
        uint8_t data[15];
    };
} UI_ellipse_t;

typedef union {
    struct {
        uint8_t  figure_name[3];
        uint32_t operate_tpyel : 3;
        uint32_t figure_tpye : 3;
        uint32_t layer : 4;
        uint32_t color : 4;
        uint32_t start_angle : 9;
        uint32_t end_angle : 9;
        uint32_t width : 10;
        uint32_t start_x : 11;
        uint32_t start_y : 11;
        uint32_t details_c : 10;
        uint32_t length_semiaxis_x : 11;
        uint32_t length_semiaxis_y : 11;
    };
    struct {
        uint8_t data[15];
    };
} UI_arc_t;

typedef union {
    struct {
        uint8_t  figure_name[3];
        uint32_t operate_tpyel : 3;
        uint32_t figure_tpye : 3;
        uint32_t layer : 4;
        uint32_t color : 4;
        uint32_t font_size : 9;
        uint32_t details_b : 9;
        uint32_t width : 10;
        uint32_t start_x : 11;
        uint32_t start_y : 11;
        uint32_t value_x1000 : 32;
    };
    struct {
        uint8_t data[15];
    };
} UI_float_t;

typedef union {
    struct {
        uint8_t  figure_name[3];
        uint32_t operate_tpyel : 3;
        uint32_t figure_tpye : 3;
        uint32_t layer : 4;
        uint32_t color : 4;
        uint32_t font_size : 9;
        uint32_t details_b : 9;
        uint32_t width : 10;
        uint32_t start_x : 11;
        uint32_t start_y : 11;
        int32_t  value : 32;
    };
    struct {
        uint8_t data[15];
    };
} UI_int_t;

typedef union {
    struct {
        uint8_t  figure_name[3];
        uint32_t operate_tpyel : 3;
        uint32_t figure_tpye : 3;
        uint32_t layer : 4;
        uint32_t color : 4;
        uint32_t font_size : 9;
        uint32_t str_length : 9;
        uint32_t width : 10;
        uint32_t start_x : 11;
        uint32_t start_y : 11;
        uint32_t details_c : 10;
        uint32_t details_d : 11;
        uint32_t details_e : 11;
        char     characater[30];
    };
    struct {
        uint8_t data[45];
    };
} UI_characater_t;

/**
 * @brief functions
 */
void UI_Init();
void UI_1_Protocol_Updata(interaction_figure_1_t *interactionFigure_1, client_custom_graphic_single_t *clientCustomGraphicSingle);
void UI_2_Protocol_Updata(interaction_figure_2_t *interactionFigure_2, client_custom_graphic_double_t *clientCustomGraphicDouble);
void UI_5_Protocol_Updata(interaction_figure_5_t *interactionFigure_5, client_custom_graphic_five_t *clientCustomGraphicFive);
void UI_7_Protocol_Updata(interaction_figure_7_t *interactionFigure_7, client_custom_graphic_seven_t *clientCustomGraphicSeven);
void UI_Char_Protocol_Updata(ext_client_custom_character_t *extClientCustomChar, client_custom_character_t *clientCustomChar);

#endif