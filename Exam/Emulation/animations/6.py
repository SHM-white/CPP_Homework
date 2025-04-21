from manimlib import *

class NQueens(Scene):
    def construct(self):
        # Title
        title = Text("N-Queens Problem").to_edge(UP)
        self.play(Write(title), run_time=1)  # 设置动画播放时间

        # Board visualization
        n = 5  # 修改皇后数量为 5
        board = Square(side_length=0.5).replicate(n * n).arrange_in_grid(n, n, buff=0)
        self.play(ShowCreation(board), run_time=2)  # 设置动画播放时间

        # Highlight search process
        def highlight_cell(row, col, color):
            cell = board[row * n + col]
            self.play(ApplyMethod(cell.set_fill, color), ApplyMethod(cell.set_opacity, 0.5), run_time=0.5)

        def unhighlight_cell(row, col):
            cell = board[row * n + col]
            self.play(ApplyMethod(cell.set_fill, None), ApplyMethod(cell.set_opacity, 0), run_time=0.5)

        # Highlight conflict
        def highlight_conflict(row1, col1, row2, col2):
            highlight_cell(row1, col1, RED)  # 使用红色标出冲突
            highlight_cell(row2, col2, RED)  # 使用红色标出冲突
            self.wait(0.3)  # 缩短等待时间
            unhighlight_cell(row1, col1)
            unhighlight_cell(row2, col2)

        # Place queens with backtracking visualization
        queens = []
        def place_queen(row, col):
            queen = Text("Q").move_to(board[row * n + col].get_center())
            queens.append(queen)
            self.play(Write(queen), run_time=0.5)

        def remove_queen():
            queen = queens.pop()
            self.play(FadeOut(queen), run_time=0.5)

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
                self.play(Write(solution_text), run_time=1)
                self.wait(0.5)  # 缩短等待时间
                self.play(FadeOut(solution_text), run_time=0.5)
                return

            for col in range(1, n + 1):
                if is_valid(solution, row, col):
                    highlight_cell(row, col - 1, YELLOW)
                    place_queen(row, col - 1)
                    dfs(row + 1, solution + [col])
                    remove_queen()
                    unhighlight_cell(row, col - 1)

        dfs(0, [])
        self.wait(1)  # 缩短等待时间
