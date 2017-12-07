Turi Create
===============

Turi Create simplifies the development of custom machine learning models. You
don't have to be a machine learning expert to add recommendations, object
detection, image classification, image similarity or activity classification to
your app.

* **Easy-to-use:** Focus on tasks instead of algorithms
* **Visual:** Built-in, streaming visualizations to explore your data
* **Flexible:** Supports text, images, audio, video and sensor data
* **Fast and Scalable:** Work with large datasets on a single machine
* **Ready To Deploy:** Export models to Core ML for use in iOS, macOS, watchOS, and tvOS apps

<img src="https://docs-assets.developer.apple.com/published/a2c37bce1f/689f61a6-1087-4112-99d9-bbfb326e3138.png" alt="Turi Create" width="600">

System Requirements
-------------------

* Python 2.7 (Python 3.5+ support coming soon).
* x86\_64 architecture.
* macOS 10.11+, Linux with glibc 2.12+ (including WSL on Windows 10).

Installation
------------

For detailed instructions for different varieties of Linux see [LINUX\_INSTALL.md](LINUX_INSTALL.md).
For common installation issues see [INSTALL\_ISSUES.md](INSTALL_ISSUES.md).

We recommend using virtualenv to use, install, or build Turi Create. 
Be sure to install virtualenv using your system pip.

```shell
pip install virtualenv
```

The method for installing *Turi Create* follows the
[standard python package installation steps](https://packaging.python.org/installing/).
To create a Python virtual environment called `venv` follow these steps:

```shell
# Create a Python virtual environment
cd ~
virtualenv venv
```

To activate your new virtual environment and install `Turi Create` in this environment, follow these steps:
```
# Active your virtual environment
source ~/venv/bin/activate

# Install Turi Create in the new virtual environment, pythonenv
(venv) pip install -U turicreate
```

The package [User Guide](https://apple.github.io/turicreate/docs/userguide) and [API Docs](https://apple.github.io/turicreate/docs/api) contain
more details on how to use Turi Create.

GPU Support
-----------

By default, `turicreate` takes a dependency on the default installation of
`mxnet`. To enable GPU support after installation of the `turicreate` package,
please perform the following steps:

 * Install CUDA 8.0 ([instructions](http://docs.nvidia.com/cuda/cuda-installation-guide-linux/))
 * Install cuDNN 5 for CUDA 8.0 ([instructions](https://developer.nvidia.com/cudnn))

Make sure to add the CUDA library path to your `LD_LIBRARY_PATH` environment
variable.  In the typical case, this means adding the following line to your
`~/.bashrc` file:

```shell
export LD_LIBRARY_PATH=/usr/local/cuda/lib64:$LD_LIBRARY_PATH
```

If you installed the cuDNN files into a separate directory, make sure to
separately add it as well. Next step is to uninstall `mxnet` and install the
CUDA-enabled `mxnet-cu80` package:

```
(pythonenv) pip uninstall -y mxnet
(pythonenv) pip install mxnet-cu80==0.11.0
```

Make sure you install the same version of MXNet as the one `turicreate` depends
on (currently `0.11.0`). If you have trouble setting up the GPU, the [MXNet
installation instructions](https://mxnet.incubator.apache.org/get_started/install.html) may
offer additional help.

Compiling
---------

Most users will prefer to pip install a release build. If you want to compile from source, See [BUILD.md](BUILD.md).

Contributing
------------

See [CONTRIBUTING.md](CONTRIBUTING.md).
