from manimlib import *

class StoneMerge(Scene):
    def construct(self):
        # Title
        title = Text("Stone Merge Simulation", font_size=24).to_edge(UP)
        self.play(Write(title))

        # Input data
        stones = [2, 5, 3, 1, 7]  # Example input
        n = len(stones)

        # Display stones
        stones_text = Text(f"Stones: {stones}", font_size=20).next_to(title, DOWN)
        self.play(Write(stones_text))

        # Initialize dp and totalCost tables
        dp_table, dp_cells = self.create_table(n, "dp")
        dp_table.to_edge(LEFT)  # Adjust table position
        total_cost_table, total_cost_cells = self.create_table(n, "totalCost")
        total_cost_table.to_edge(RIGHT)  # Adjust table position
        self.play(Write(dp_table), Write(total_cost_table))

        # Initialize dp and totalCost values
        dp = [[float('inf')] * n for _ in range(n)]
        total_cost = [[float('inf')] * n for _ in range(n)]

        for i in range(n):
            dp[i][i] = stones[i]
            total_cost[i][i] = 0
            self.update_table_cell(dp_cells, i, i, stones[i])
            self.update_table_cell(total_cost_cells, i, i, 0)

        # Formula display
        formula_text = Text("Formula: ", font_size=20).to_edge(DOWN)
        self.play(Write(formula_text))

        # Simulate dynamic programming process
        for length in range(2, n + 1):  # length of the range
            for i in range(n - length + 1):
                j = i + length - 1
                self.highlight_table_cell(dp_cells, i, j, color=BLUE)
                self.highlight_table_cell(total_cost_cells, i, j, color=BLUE)

                for k in range(i, j):
                    # Create formula with colored text using t2c
                    formula_text_content = (
                        f"totalCost[{i+1}][{j+1}] = min("
                        f"totalCost[{i+1}][{k+1}] + "
                        f"totalCost[{k+2}][{j+1}] + "
                        f"dp[{i+1}][{k+1}] + "
                        f"dp[{k+2}][{j+1}])"
                    )
                    formula = Text(
                        formula_text_content,
                        font_size=16,
                        t2c={
                            f"totalCost[{i+1}][{k+1}]": RED,
                            f"totalCost[{k+2}][{j+1}]": GREEN,
                            f"dp[{i+1}][{k+1}]": YELLOW,
                            f"dp[{k+2}][{j+1}]": ORANGE,
                        }
                    ).to_edge(DOWN)
                    self.play(Transform(formula_text, formula))

                    # Highlight cells with different colors simultaneously
                    self.highlight_table_cell(total_cost_cells, i, k, color=RED)
                    self.highlight_table_cell(total_cost_cells, k + 1, j, color=GREEN)
                    self.highlight_table_cell(dp_cells, i, k, color=YELLOW)
                    self.highlight_table_cell(dp_cells, k + 1, j, color=ORANGE)

                    new_cost = total_cost[i][k] + total_cost[k + 1][j] + dp[i][k] + dp[k + 1][j]
                    if new_cost < total_cost[i][j]:
                        total_cost[i][j] = new_cost
                        dp[i][j] = dp[i][k] + dp[k + 1][j]
                        self.update_table_cell(total_cost_cells, i, j, new_cost)
                        self.update_table_cell(dp_cells, i, j, dp[i][j])

        # Final result
        result_text = Text(f"Minimum Total Cost: {total_cost[0][n-1]}", font_size=20).to_edge(DOWN)
        self.play(Transform(formula_text, result_text))
        self.wait(2)

    def create_table(self, n, label):
        """Create a table with n x n cells."""
        table = VGroup()
        cells = []
        for i in range(n):
            row = []
            for j in range(n):
                cell = Rectangle(width=1, height=0.5)
                cell_text = Text("∞", font_size=16).move_to(cell.get_center())
                cell_group = VGroup(cell, cell_text)
                row.append(cell_group)
                table.add(cell_group)
            cells.append(row)
        table.arrange_in_grid(n_rows=n, n_cols=n, buff=0.1)  # Corrected parameter names
        label_text = Text(label, font_size=20).next_to(table, UP)
        return VGroup(label_text, table), cells

    def update_table_cell(self, cells, row, col, value):
        """Update the value of a specific cell in the table."""
        cell_group = cells[row][col]
        cell_text = Text(str(value), font_size=16).move_to(cell_group[0].get_center())
        self.play(Transform(cell_group[1], cell_text))

    def highlight_table_cell(self, cells, row, col, color):
        """Highlight a specific cell in the table."""
        cell_group = cells[row][col]
        self.play(Indicate(cell_group[0], color=color))
