from setuptools import find_packages
from setuptools import setup

setup(
    name='ros2_fundamentals_examples',
    version='0.0.0',
    packages=find_packages(
        include=('ros2_fundamentals_examples', 'ros2_fundamentals_examples.*')),
)
