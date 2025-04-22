from manimlib import *

class NQueens(Scene):
    def construct(self):
        # Title
        title = Text("N-Queens Problem").to_edge(UP)
        self.play(Write(title), run_time=0.5)  # 缩短动画播放时间

        # Board visualization
        n = 5  # 修改皇后数量为 5

        # 创建背景棋盘
        background_board = Square(side_length=0.5).replicate(n * n).arrange_in_grid(n, n, buff=0)
        for cell in background_board:
            cell.set_stroke(WHITE, 1)  # 设置边框颜色
            cell.set_fill(None, 0)  # 设置背景透明
        self.add(background_board)  # 添加背景棋盘到场景中

        # 创建用于动画的棋盘
        board = Square(side_length=0.5).replicate(n * n).arrange_in_grid(n, n, buff=0)
        self.play(ShowCreation(board), run_time=1)  # 缩短动画播放时间

        # Highlight search process
        def highlight_cell(row, col, color):
            cell = board[row * n + col]
            self.play(ApplyMethod(cell.set_fill, color), ApplyMethod(cell.set_opacity, 0.5), run_time=0.05)  # 动画时间减半

        def unhighlight_cell(row, col):
            cell = board[row * n + col]
            self.play(ApplyMethod(cell.set_fill, None), ApplyMethod(cell.set_opacity, 0), run_time=0.05)  # 恢复为透明
            self.play(ApplyMethod(cell.set_stroke, WHITE, 1), run_time=0.1)  # 恢复边框为白色

        # Highlight conflict
        def highlight_conflict(row1, col1, row2, col2):
            cell1 = board[row1 * n + col1]
            cell2 = board[row2 * n + col2]
            for _ in range(2):  # 快闪两次
                self.play(ApplyMethod(cell1.set_color, RED), ApplyMethod(cell1.set_opacity, 0.5),
                          ApplyMethod(cell2.set_color, RED), ApplyMethod(cell2.set_opacity, 0.5), run_time=0.05)
                self.play(ApplyMethod(cell1.set_color, None), ApplyMethod(cell1.set_opacity, 0),
                          ApplyMethod(cell2.set_color, None), ApplyMethod(cell2.set_opacity, 0), run_time=0.05)

        # Place queens with backtracking visualization
        queens = []
        def place_queen(row, col):
            queen = Text("Q").move_to(board[row * n + col].get_center())
            queens.append(queen)
            self.play(Write(queen), run_time=0.15)  # 动画时间减半

        def remove_queen():
            queen = queens.pop()
            self.play(FadeOut(queen), run_time=0.15)  # 动画时间减半

        def is_valid(solution, row, col):
            for r in range(row):
                c = solution[r]
                if c == col or abs(c - col) == abs(r - row):
                    highlight_conflict(r, c - 1, row, col - 1)  # 高亮冲突位置
                    return False
            return True

        def dfs(row, solution):
            if row == n:
                # Display solution
                solution_text = Text("Solution: " + " ".join(map(str, solution))).next_to(board, DOWN)
                self.play(Write(solution_text), run_time=0.5)
                self.wait(0.5)  # 等待时间减半
                self.play(FadeOut(solution_text), run_time=0.15)  # 动画时间减半
                return

            for col in range(1, n + 1):
                if is_valid(solution, row, col):
                    highlight_cell(row, col - 1, YELLOW)
                    place_queen(row, col - 1)
                    dfs(row + 1, solution + [col])
                    remove_queen()
                    unhighlight_cell(row, col - 1)

        dfs(0, [])
        self.wait(0.25)  # 等待时间减半
