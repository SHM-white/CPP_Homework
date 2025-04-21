from manimlib import *

class PerfectNumberCount(Scene):
    def construct(self):
        # Title
        title = Text("Perfect Numbers Count in Range", font_size=16).to_edge(UP)
        self.play(Write(title))

        # Input visualization
        m, n = 1, 10
        input_text = Text(f"Input:\nm={m}, n={n}", font_size=12).next_to(title, DOWN)
        self.play(Write(input_text))
        self.wait(1)

        # Perfect numbers list
        perfect_numbers = [6, 28, 496, 8128, 33550336, 8589869056, 137438691328]
        perfect_numbers_text = Text(
            "Perfect Numbers:\n" + "\n".join(map(str, perfect_numbers)), font_size=12
        ).next_to(input_text, DOWN)
        self.play(Write(perfect_numbers_text))
        self.wait(1)

        # Find range indices with visualization
        b = next((i for i, num in enumerate(perfect_numbers) if num >= m), len(perfect_numbers))
        b_text = Text(f"First index >= {m}: {b}", font_size=12).next_to(perfect_numbers_text, DOWN)
        self.play(Write(b_text))
        self.wait(1)

        e = next((i for i, num in enumerate(perfect_numbers) if num > n), len(perfect_numbers))
        e_text = Text(f"First index > {n}: {e}", font_size=12).next_to(b_text, DOWN)
        self.play(Write(e_text))
        self.wait(1)

        # Count perfect numbers in range
        count = max(0, e - b)
        result_text = Text(f"Perfect Numbers Count: {count}", font_size=12).next_to(e_text, DOWN)
        self.play(Write(result_text))
        self.wait(2)
