from manimlib import *
from manimlib.animation.creation import ShowCreation  # Correct import

class LaundryProcess(Scene):
    def construct(self):
        # Title
        title = Text("Laundry Process Simulation", font_size=24).to_edge(UP)
        self.play(Write(title))

        # Washers and dryers
        washers = [100, 10, 1]  # Example data: 3 washers with different times
        dryers = [10, 10]       # Example data: 2 dryers with equal times
        washers_text = Text(f"Washers: {washers}", font_size=20).next_to(title, DOWN)
        dryers_text = Text(f"Dryers: {dryers}", font_size=20).next_to(washers_text, DOWN)
        self.play(Write(washers_text), Write(dryers_text))

        # Priority queue simulation for washers
        washer_queue_text = Text("Washer Priority Queue:", font_size=20).next_to(dryers_text, DOWN)
        self.play(Write(washer_queue_text))
        washer_queue = VGroup(
            Text(f"(1, 1)", font_size=16),
            Text(f"(10, 10)", font_size=16),
            Text(f"(100, 100)", font_size=16)
        ).arrange(DOWN, aligned_edge=LEFT).next_to(washer_queue_text, DOWN)
        self.play(Write(washer_queue))
        self.wait(2)

        # Washed items priority queue
        washed_queue_text = Text("Washed Priority Queue:", font_size=20).next_to(washer_queue, DOWN)
        self.play(Write(washed_queue_text))
        washed_queue = VGroup().next_to(washed_queue_text, DOWN)

        # Initialize result display
        result_text = Text("Total Time: 0 min", font_size=20).to_edge(RIGHT)
        self.play(Write(result_text))

        # Simulate washing process
        for i in range(2):  # Process 2 items
            process_text = Text(f"Processing item {i + 1}...", font_size=16).to_edge(LEFT)  # Moved to the side
            self.play(Write(process_text))
            self.wait(1)

            # Remove the top washer from the queue
            top_washer = washer_queue[0]
            washer_queue.remove(top_washer)
            self.play(FadeOut(top_washer))

            # Update washer time and reinsert into the queue
            washer_time, cycle_time = map(int, top_washer.get_text()[1:-1].split(", "))
            new_time = washer_time + cycle_time
            new_washer = Text(f"({new_time}, {cycle_time})", font_size=16)
            washer_queue.add(new_washer)
            washer_queue = VGroup(*sorted(washer_queue, key=lambda x: int(x.get_text()[1:-1].split(", ")[0])))
            washer_queue.arrange(DOWN, aligned_edge=LEFT).next_to(washer_queue_text, DOWN)
            self.play(Write(new_washer))

            # Add the finished time to washed items
            washed_item = Text(f"{washer_time}", font_size=16)
            washed_queue.add(washed_item)
            washed_queue.arrange(DOWN, aligned_edge=LEFT).next_to(washed_queue_text, DOWN)
            self.play(Write(washed_item))
            self.play(FadeOut(process_text))
            self.wait(1)

        # Priority queue simulation for dryers
        dryer_queue_text = Text("Dryer Priority Queue:", font_size=20).next_to(washed_queue, DOWN)
        self.play(Write(dryer_queue_text))
        dryer_queue = VGroup(
            Text(f"(10, 10)", font_size=16),
            Text(f"(10, 10)", font_size=16)
        ).arrange(DOWN, aligned_edge=LEFT).next_to(dryer_queue_text, DOWN)
        self.play(Write(dryer_queue))
        self.wait(2)

        # Simulate drying process
        result_time = 0
        while len(washed_queue) > 0:
            drying_text = Text("Drying item...", font_size=16).to_edge(LEFT)  # Moved to the side
            self.play(Write(drying_text))
            self.wait(1)

            # Remove the top washed item
            top_washed = washed_queue[-1]
            washed_queue.remove(top_washed)
            self.play(FadeOut(top_washed))

            # Remove the top dryer from the queue
            top_dryer = dryer_queue[0]
            dryer_queue.remove(top_dryer)
            self.play(FadeOut(top_dryer))

            # Update dryer time and reinsert into the queue
            dryer_time, cycle_time = map(int, top_dryer.get_text()[1:-1].split(", "))
            new_time = dryer_time + cycle_time
            new_dryer = Text(f"({new_time}, {cycle_time})", font_size=16)
            dryer_queue.add(new_dryer)
            dryer_queue = VGroup(*sorted(dryer_queue, key=lambda x: int(x.get_text()[1:-1].split(", ")[0])))
            dryer_queue.arrange(DOWN, aligned_edge=LEFT).next_to(dryer_queue_text, DOWN)
            self.play(Write(new_dryer))

            # Update result time
            wash_time = int(top_washed.get_text())
            result_time = max(result_time, wash_time + dryer_time)
            updated_result_text = Text(f"Total Time: {result_time} min", font_size=20).to_edge(RIGHT)
            self.play(Transform(result_text, updated_result_text))  # Update result display
            self.play(FadeOut(drying_text))
            self.wait(1)

        # Final result
        self.play(Write(result_text))
        self.wait(2)
