from setuptools import find_packages
from setuptools import setup

setup(
    name='rero_ros',
    version='0.0.0',
    packages=find_packages(
        include=('rero_ros', 'rero_ros.*')),
)
