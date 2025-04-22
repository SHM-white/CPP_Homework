from manimlib import *

class MinMaxDifferenceExplanation(Scene):
    def construct(self):
        # Title
        title = Text("Min-Max Difference Game Explanation", font_size=36).to_edge(UP)
        self.play(Write(title), run_time=0.5)

        # Input arrays
        a = [2, 14, 7, 14]
        b = [5, 10, 9, 22]
        n = len(a)

        # Display input arrays
        a_text = Text("Array A: " + str(a), font_size=28).to_edge(LEFT).shift(UP * 2)
        b_text = Text("Array B: " + str(b), font_size=28).to_edge(LEFT).shift(UP * 0)  # 下移半行
        self.play(Write(a_text), Write(b_text), run_time=0.5)

        # Sort arrays
        a.sort()
        b.sort()
        sorted_a_text = Text("Sorted A: " + str(a), font_size=28).next_to(a_text, DOWN)
        sorted_b_text = Text("Sorted B: " + str(b), font_size=28).next_to(b_text, DOWN).shift(DOWN * 0.25)  # 再下移半行
        self.play(Write(sorted_a_text), Write(sorted_b_text), run_time=0.5)

        # Explanation of the goal
        goal_text = Text("Goal: Maximize |x - y|", font_size=28).to_edge(DOWN)
        self.play(Write(goal_text), run_time=0.5)

        # Highlight the process of finding the maximum difference
        result = 0
        result_text = Text("Result: 0", font_size=28).to_edge(DOWN).shift(UP)
        self.play(Write(result_text), run_time=0.5)

        for i, ai in enumerate(a):
            # Explain current element from A
            current_a_text = Text(f"Current A[{i}] = {ai}", font_size=24).next_to(sorted_a_text, DOWN)
            self.play(Write(current_a_text), run_time=0.5)

            # Find the closest element in B
            min_distance = abs(b[0] - ai)
            min_distance_index = 0
            for j, bj in enumerate(b):
                if abs(bj - ai) < min_distance:
                    min_distance = abs(bj - ai)
                    min_distance_index = j

            # Highlight the closest element in B
            closest_b_text = Text(f"Closest B[{min_distance_index}] = {b[min_distance_index]}", font_size=24).next_to(sorted_b_text, DOWN).shift(DOWN * 0.25)  # 再下移半行
            self.play(Write(closest_b_text), run_time=0.5)

            # Update result
            result = max(result, min_distance)
            updated_result_text = Text(f"Result: {result}", font_size=28).to_edge(DOWN).shift(UP)
            self.play(Transform(result_text, updated_result_text), run_time=0.5)

            # Remove highlights
            self.play(FadeOut(current_a_text), FadeOut(closest_b_text), run_time=0.5)

        # Final result explanation
        final_result_text = Text(f"Final Result: {result}", font_size=28).to_edge(DOWN).shift(UP * 1.5)
        explanation_text = Text("This ensures the maximum |x - y| is achieved.", font_size=24).next_to(final_result_text, UP)
        self.play(Write(final_result_text), Write(explanation_text), run_time=0.5)
        self.wait(2)
