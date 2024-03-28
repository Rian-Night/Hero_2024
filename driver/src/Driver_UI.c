#include "Driver_UI.h"
#include "handle.h"

void UI_1_Protocol_Updata(interaction_figure_1_t *interactionFigure_1, client_custom_graphic_single_t *clientCustomGraphicSingle) {
    clientCustomGraphicSingle->data_cmd_id = 0xF101;
    clientCustomGraphicSingle->send_id     = ProtocolData.gameRobotstatus.robot_id;
    clientCustomGraphicSingle->receiver_id = 0x100 + ProtocolData.gameRobotstatus.robot_id;
    for (int i = 6; i < sizeof(clientCustomGraphicSingle->data); i++) {
        clientCustomGraphicSingle->data[i] = interactionFigure_1->data[i];
    }
}

void UI_2_Protocol_Updata(interaction_figure_2_t *interactionFigure_2, client_custom_graphic_double_t *clientCustomGraphicDouble) {
    clientCustomGraphicDouble->data_cmd_id = 0xF102;
    clientCustomGraphicDouble->send_id     = ProtocolData.gameRobotstatus.robot_id;
    clientCustomGraphicDouble->receiver_id = 0x100 + ProtocolData.gameRobotstatus.robot_id;
    for (int i = 6; i < sizeof(clientCustomGraphicDouble->data); i++) {
        clientCustomGraphicDouble->data[i] = interactionFigure_2->data[i];
    }
}

void UI_5_Protocol_Updata(interaction_figure_5_t *interactionFigure_5, client_custom_graphic_five_t *clientCustomGraphicFive) {
    clientCustomGraphicFive->data_cmd_id = 0xF103;
    clientCustomGraphicFive->send_id     = ProtocolData.gameRobotstatus.robot_id;
    clientCustomGraphicFive->receiver_id = 0x100 + ProtocolData.gameRobotstatus.robot_id;
    for (int i = 6; i < sizeof(clientCustomGraphicFive->data); i++) {
        clientCustomGraphicFive->data[i] = interactionFigure_5->data[i];
    }
}

void UI_7_Protocol_Updata(interaction_figure_7_t *interactionFigure_7, client_custom_graphic_seven_t *clientCustomGraphicSeven) {
    clientCustomGraphicSeven->data_cmd_id = 0xF104;
    clientCustomGraphicSeven->send_id     = ProtocolData.gameRobotstatus.robot_id;
    clientCustomGraphicSeven->receiver_id = 0x100 + ProtocolData.gameRobotstatus.robot_id;
    for (int i = 6; i < sizeof(clientCustomGraphicSeven->data); i++) {
        clientCustomGraphicSeven->data[i] = interactionFigure_7->data[i];
    }
}

void UI_Char_Protocol_Updata(ext_client_custom_character_t *extClientCustomChar, client_custom_character_t *clientCustomChar) {
    clientCustomChar->data_cmd_id = 0xF110;
    clientCustomChar->send_id     = ProtocolData.gameRobotstatus.robot_id;
    clientCustomChar->receiver_id = 0x100 + ProtocolData.gameRobotstatus.robot_id;
    for (int i = 6; i < sizeof(clientCustomChar->data); i++) {
        clientCustomChar->data[i] = extClientCustomChar->data[i];
    }
}

/**
 * @brief 自定义图形并初始化， 具体数据采用生成器，
 * @details 由于单图层没有图形数目限制（可能有，但是上限很高），所以图层管理暂时不考虑。
 *          但如果使用大量ui，且涉及到复杂ui的动态显现（即一次性删除大量图形），建议图层隔离管理
 *          设定静态id 首位0， 动态id 首位9
 *          次位为图形类型 按类型依次排序
 *          Line:0 Rec:1 Circle:2 Elli:3 Arc:4 Float:5 Int:6 Char:7
 *          末位 按顺序即可
 */

void UI_Init() {
    // 定义  ##采用指针， 因为操作符 -> 适用于指针 而 dot 适用于struct / union
    //       ##若生成器给出操作符为dot，就更改为 struct/union
    UI_line_t *ui____Line_1, *ui____Line_2, *ui____Line_3, *ui____Line_4;
    UI_line_t *ui____Line_5, *ui____Line_6, *ui____Line_7;

    UI_characater_t ui____TargetSpeed;

    UI_int_t *ui____Value_TargetSpeed;

    // 赋值
    ui____Line_1->figure_name[0] = 0;
    ui____Line_1->figure_name[1] = 0;
    ui____Line_1->figure_name[2] = 0;
    ui____Line_1->operate_tpyel  = 1;
    ui____Line_1->figure_tpye    = 0;
    ui____Line_1->layer          = 0;
    ui____Line_1->start_x        = 880;
    ui____Line_1->start_y        = 540;
    ui____Line_1->end_x          = 1040;
    ui____Line_1->end_y          = 540;
    ui____Line_1->color          = 2;
    ui____Line_1->width          = 3;

    ui____Line_2->figure_name[0] = 0;
    ui____Line_2->figure_name[1] = 0;
    ui____Line_2->figure_name[2] = 1;
    ui____Line_2->operate_tpyel  = 1;
    ui____Line_2->figure_tpye    = 0;
    ui____Line_2->layer          = 0;
    ui____Line_2->start_x        = 890;
    ui____Line_2->start_y        = 520;
    ui____Line_2->end_x          = 1030;
    ui____Line_2->end_y          = 520;
    ui____Line_2->color          = 2;
    ui____Line_2->width          = 3;

    ui____Line_3->figure_name[0] = 0;
    ui____Line_3->figure_name[1] = 0;
    ui____Line_3->figure_name[2] = 2;
    ui____Line_3->operate_tpyel  = 1;
    ui____Line_3->figure_tpye    = 0;
    ui____Line_3->layer          = 0;
    ui____Line_3->start_x        = 900;
    ui____Line_3->start_y        = 500;
    ui____Line_3->end_x          = 1020;
    ui____Line_3->end_y          = 500;
    ui____Line_3->color          = 2;
    ui____Line_3->width          = 3;

    ui____Line_4->figure_name[0] = 0;
    ui____Line_4->figure_name[1] = 0;
    ui____Line_4->figure_name[2] = 3;
    ui____Line_4->operate_tpyel  = 1;
    ui____Line_4->figure_tpye    = 0;
    ui____Line_4->layer          = 0;
    ui____Line_4->start_x        = 925;
    ui____Line_4->start_y        = 470;
    ui____Line_4->end_x          = 995;
    ui____Line_4->end_y          = 470;
    ui____Line_4->color          = 2;
    ui____Line_4->width          = 3;

    ui____Line_5->figure_name[0] = 0;
    ui____Line_5->figure_name[1] = 0;
    ui____Line_5->figure_name[2] = 4;
    ui____Line_5->operate_tpyel  = 1;
    ui____Line_5->figure_tpye    = 0;
    ui____Line_5->layer          = 0;
    ui____Line_5->start_x        = 935;
    ui____Line_5->start_y        = 440;
    ui____Line_5->end_x          = 985;
    ui____Line_5->end_y          = 440;
    ui____Line_5->color          = 2;
    ui____Line_5->width          = 3;

    ui____Line_6->figure_name[0] = 0;
    ui____Line_6->figure_name[1] = 0;
    ui____Line_6->figure_name[2] = 5;
    ui____Line_6->operate_tpyel  = 1;
    ui____Line_6->figure_tpye    = 0;
    ui____Line_6->layer          = 0;
    ui____Line_6->start_x        = 940;
    ui____Line_6->start_y        = 410;
    ui____Line_6->end_x          = 980;
    ui____Line_6->end_y          = 410;
    ui____Line_6->color          = 2;
    ui____Line_6->width          = 3;

    ui____Line_7->figure_name[0] = 0;
    ui____Line_7->figure_name[1] = 0;
    ui____Line_7->figure_name[2] = 6;
    ui____Line_7->operate_tpyel  = 1;
    ui____Line_7->figure_tpye    = 0;
    ui____Line_7->layer          = 0;
    ui____Line_7->start_x        = 960;
    ui____Line_7->start_y        = 410;
    ui____Line_7->end_x          = 960;
    ui____Line_7->end_y          = 539;
    ui____Line_7->color          = 2;
    ui____Line_7->width          = 3;

    ui____Value_TargetSpeed->figure_name[0] = 9;
    ui____Value_TargetSpeed->figure_name[1] = 6;
    ui____Value_TargetSpeed->figure_name[2] = 0;
    ui____Value_TargetSpeed->operate_tpyel  = 1;
    ui____Value_TargetSpeed->figure_tpye    = 6;
    ui____Value_TargetSpeed->layer          = 1;
    ui____Value_TargetSpeed->font_size      = 40;
    ui____Value_TargetSpeed->start_x        = 50;
    ui____Value_TargetSpeed->start_y        = 350;
    ui____Value_TargetSpeed->color          = 6;
    ui____Value_TargetSpeed->value          = 0;
    ui____Value_TargetSpeed->width          = 4;

    ui____TargetSpeed.figure_name[0] = 0;
    ui____TargetSpeed.figure_name[1] = 7;
    ui____TargetSpeed.figure_name[2] = 0;
    ui____TargetSpeed.operate_tpyel  = 1;
    ui____TargetSpeed.figure_tpye    = 7;
    ui____TargetSpeed.layer          = 1;
    ui____TargetSpeed.font_size      = 40;
    ui____TargetSpeed.start_x        = 50;
    ui____TargetSpeed.start_y        = 400;
    ui____TargetSpeed.color          = 6;
    ui____TargetSpeed.str_length     = 12;
    ui____TargetSpeed.width          = 4;
    strcpy(ui____TargetSpeed.characater, "TagertSpeed:");

    // 打包
    for (int i = 0; i < sizeof(interactionFigure_1_0.data); i++) {
        interactionFigure_1_0.data[i] = ui____Value_TargetSpeed->data[i];
    }

    for (int i = 0; i < 15; i++) {
        interactionFigure_7_0.data[i]          = ui____Line_1->data[i];
        interactionFigure_7_0.data[i + 15]     = ui____Line_2->data[i];
        interactionFigure_7_0.data[i + 15 * 2] = ui____Line_3->data[i];
        interactionFigure_7_0.data[i + 15 * 3] = ui____Line_4->data[i];
        interactionFigure_7_0.data[i + 15 * 4] = ui____Line_5->data[i];
        interactionFigure_7_0.data[i + 15 * 5] = ui____Line_6->data[i];
        interactionFigure_7_0.data[i + 15 * 6] = ui____Line_7->data[i];
    }

    for (int i = 0; i < sizeof(extClientCustomChar_0.data); i++) {
        extClientCustomChar_0.data[i] = ui____TargetSpeed.data[i];
    }
}
