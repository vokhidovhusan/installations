# PyTorch on WINDOWS 10

## Prerequirements
1.NVIDIA GPU driver

2.CUDA toolkit

3.CUDNN library

4.Python x.x

5. (optional) [Conda] (https://docs.conda.io/projects/conda/en/latest/user-guide/install/windows.html) or [Virtualenv]: (https://virtualenv.pypa.io/en/stable/)

[GitHub](http://github.com)

## Create new conda virtual invoronment (optional)
```
conda create -n yourenvname python=x.x anaconda
```
yourenvname: can be anything.
python=x.x: choose right python version 
Example  
```
conda create -n pytorch_env python=3.9 anaconda
```

After creating a virtual environment now we need to activate it using

```
conda activate yourenvname
```

## Install PyTorch 

```
conda install pytorch -c pytorch
```

## Install torchvision

```
pip3 install torchvision
```

## Test
```
python
>>> import torch
>>> torch.__version__
'1.8.1'
>>>
```
