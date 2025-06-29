// #pragma once
// #include "clone.h"
// #include "Eigen/SparseLU"
// #include <Eigen/LU>  // ✅ 这是 PartialPivLU 所在头文件


// namespace USTC_CG
// {
// class SeamLess : public Clone
// {
//     public:
//      SeamLess() = default;
//      ~SeamLess() = default;

//      void apply_clone(
//          std::shared_ptr<Image> data,
//          std::shared_ptr<CompSourceImage> source_image,
//          const ImVec2& position) override;

//      Eigen::MatrixXd s_Matrix_A(
//          const ImVec2& start_,
//          const ImVec2& end_);

//      Eigen::VectorXd s_Vector_b(
//          std::shared_ptr<Image> target_image,
//          std::shared_ptr<CompSourceImage> source_image,
//          const ImVec2& position,
//          const ImVec2& start_,
//          const ImVec2& end_,
//          int color);

//     private:
//      int s_x, s_y, e_x, e_y;
//      int m, n;
// };
// } // namespace USTC_CG







#pragma once

#include "comp_source_image.h"
#include "clone.h"
#include <memory>
#include <Eigen/Sparse>
#include <imgui.h>

namespace USTC_CG {

class SeamLess : public Clone {
public:
    // 生成稀疏泊松矩阵 A
    Eigen::SparseMatrix<double> s_Matrix_A(const ImVec2& start_, const ImVec2& end_);

    // 重写克隆策略接口（使用稀疏LU）
    void apply_clone(
        std::shared_ptr<Image> data,
        std::shared_ptr<CompSourceImage> source_image,
        const ImVec2& position) override;

    void prepare();

   private:
    // 区域尺寸和坐标
    int m = 0, n = 0;
    int s_x = 0, s_y = 0, e_x = 0, e_y = 0;

    Eigen::SparseMatrix<double> Delta;
    
};
} // namespace USTC_CG
