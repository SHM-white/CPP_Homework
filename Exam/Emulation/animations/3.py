from manimlib import *
from manimlib.animation.creation import ShowCreation  # Correct import

class MinDistance(Scene):
    def construct(self):
        # Title
        title = Text("Optimal Strategy Game Simulation", font_size=24).to_edge(UP)
        self.play(Write(title))

        # Arrays
        a = [2, 14, 7, 14]
        b = [5, 10, 9, 22]
        a_text = Text(f"Array A: {a}", font_size=24).next_to(title, DOWN)
        b_text = Text(f"Array B: {b}", font_size=24).next_to(a_text, DOWN)
        self.play(Write(a_text), Write(b_text))

        # Sort arrays
        a_sorted = sorted(a)
        b_sorted = sorted(b)
        sorted_text = Text(f"Sorted A: {a_sorted}, Sorted B: {b_sorted}", font_size=24).next_to(b_text, DOWN)
        self.play(Write(sorted_text))

        # Simulate the game
        x, y = 0, 0
        while a_sorted and b_sorted:
            if a_sorted[-1] > b_sorted[-1]:
                x = a_sorted.pop()
            else:
                y = b_sorted.pop()

        # Handle remaining elements
        if a_sorted:
            x = a_sorted.pop()
        if b_sorted:
            y = b_sorted.pop()

        # Display result
        result_text = Text(f"Result: |{x} - {y}| = {abs(x - y)}", font_size=24).next_to(sorted_text, DOWN)
        self.play(Write(result_text))
        self.wait(2)
