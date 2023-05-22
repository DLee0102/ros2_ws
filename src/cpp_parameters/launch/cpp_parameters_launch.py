from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package="cpp_parameters",
            executable="minimal_param_node",
            name="custom_minimal_param_node",
            output="screen",    # ensure our output is printed in our console
            emulate_tty=True,   # ensure our output is printed in our console
            parameters=[
                {"my_parameter": "earth"}
            ]
        )
    ])