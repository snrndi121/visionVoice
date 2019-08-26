
# 4차시도
# 3차 성공(Epoch = 20)을 input_weight로 설정함.
# hdf5 : lips_weight_ver2.hdf5
# config : lips_config.pickle
Using TensorFlow backend.
Parsing annotation files
Training images per class:
{'bg': 0,
 'shape_a': 560,
 'shape_e': 532,
 'shape_eu': 552,
 'shape_i': 518,
 'shape_none': 600,
 'shape_o': 590,
 'shape_u': 600,
 'shape_ui': 598}
Num classes (including bg) = 9
Config has been written to /content/gdrive/My Drive/keras-frcnn/lips_config.pickle, and can be loaded when testing to ensure correct results
Num train samples 4120
Num val samples 430
WARNING: Logging before flag parsing goes to stderr.
W0824 17:19:29.045511 140464690390912 deprecation_wrapper.py:119] From /usr/local/lib/python3.6/dist-packages/keras/backend/tensorflow_backend.py:72: The name tf.get_default_graph is deprecated. Please use tf.compat.v1.get_default_graph instead.

W0824 17:19:29.061072 140464690390912 deprecation_wrapper.py:119] From /usr/local/lib/python3.6/dist-packages/keras/backend/tensorflow_backend.py:515: The name tf.placeholder is deprecated. Please use tf.compat.v1.placeholder instead.

W0824 17:19:29.069431 140464690390912 deprecation_wrapper.py:119] From /usr/local/lib/python3.6/dist-packages/keras/backend/tensorflow_backend.py:4048: The name tf.random_uniform is deprecated. Please use tf.random.uniform instead.

W0824 17:19:29.095561 140464690390912 deprecation_wrapper.py:119] From /usr/local/lib/python3.6/dist-packages/keras/backend/tensorflow_backend.py:1897: The name tf.nn.fused_batch_norm is deprecated. Please use tf.compat.v1.nn.fused_batch_norm instead.

W0824 17:19:29.097124 140464690390912 deprecation_wrapper.py:119] From /usr/local/lib/python3.6/dist-packages/keras/backend/tensorflow_backend.py:3878: The name tf.nn.max_pool is deprecated. Please use tf.nn.max_pool2d instead.

W0824 17:19:30.267974 140464690390912 deprecation_wrapper.py:119] From /usr/local/lib/python3.6/dist-packages/keras/backend/tensorflow_backend.py:4025: The name tf.random_normal is deprecated. Please use tf.random.normal instead.

W0824 17:19:30.306995 140464690390912 deprecation_wrapper.py:119] From /content/gdrive/My Drive/keras-frcnn/keras_frcnn/RoiPoolingConv.py:105: The name tf.image.resize_images is deprecated. Please use tf.image.resize instead.

W0824 17:19:31.259393 140464690390912 deprecation_wrapper.py:119] From /usr/local/lib/python3.6/dist-packages/keras/backend/tensorflow_backend.py:3882: The name tf.nn.avg_pool is deprecated. Please use tf.nn.avg_pool2d instead.

loading weights from /content/gdrive/My Drive/keras-frcnn/lip_weight.hdf5
W0824 17:19:31.872316 140464690390912 deprecation_wrapper.py:119] From /usr/local/lib/python3.6/dist-packages/keras/backend/tensorflow_backend.py:172: The name tf.get_default_session is deprecated. Please use tf.compat.v1.get_default_session instead.

2019-08-24 17:19:31.877409: I tensorflow/core/platform/profile_utils/cpu_utils.cc:94] CPU Frequency: 2300000000 Hz
2019-08-24 17:19:31.877763: I tensorflow/compiler/xla/service/service.cc:168] XLA service 0x82b7d40 executing computations on platform Host. Devices:
2019-08-24 17:19:31.877798: I tensorflow/compiler/xla/service/service.cc:175]   StreamExecutor device (0): <undefined>, <undefined>
2019-08-24 17:19:31.880014: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcuda.so.1
2019-08-24 17:19:32.048155: I tensorflow/stream_executor/cuda/cuda_gpu_executor.cc:1005] successful NUMA node read from SysFS had negative value (-1), but there must be at least one NUMA node, so returning NUMA node zero
2019-08-24 17:19:32.048870: I tensorflow/compiler/xla/service/service.cc:168] XLA service 0x8750380 executing computations on platform CUDA. Devices:
2019-08-24 17:19:32.048904: I tensorflow/compiler/xla/service/service.cc:175]   StreamExecutor device (0): Tesla T4, Compute Capability 7.5
2019-08-24 17:19:32.049118: I tensorflow/stream_executor/cuda/cuda_gpu_executor.cc:1005] successful NUMA node read from SysFS had negative value (-1), but there must be at least one NUMA node, so returning NUMA node zero
2019-08-24 17:19:32.049663: I tensorflow/core/common_runtime/gpu/gpu_device.cc:1640] Found device 0 with properties:
name: Tesla T4 major: 7 minor: 5 memoryClockRate(GHz): 1.59
pciBusID: 0000:00:04.0
2019-08-24 17:19:32.050043: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcudart.so.10.0
2019-08-24 17:19:32.051358: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcublas.so.10.0
2019-08-24 17:19:32.052815: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcufft.so.10.0
2019-08-24 17:19:32.053191: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcurand.so.10.0
2019-08-24 17:19:32.054771: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcusolver.so.10.0
2019-08-24 17:19:32.055922: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcusparse.so.10.0
2019-08-24 17:19:32.059348: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcudnn.so.7
2019-08-24 17:19:32.059482: I tensorflow/stream_executor/cuda/cuda_gpu_executor.cc:1005] successful NUMA node read from SysFS had negative value (-1), but there must be at least one NUMA node, so returning NUMA node zero
2019-08-24 17:19:32.059993: I tensorflow/stream_executor/cuda/cuda_gpu_executor.cc:1005] successful NUMA node read from SysFS had negative value (-1), but there must be at least one NUMA node, so returning NUMA node zero
2019-08-24 17:19:32.060453: I tensorflow/core/common_runtime/gpu/gpu_device.cc:1763] Adding visible gpu devices: 0
2019-08-24 17:19:32.060512: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcudart.so.10.0
2019-08-24 17:19:32.061463: I tensorflow/core/common_runtime/gpu/gpu_device.cc:1181] Device interconnect StreamExecutor with strength 1 edge matrix:
2019-08-24 17:19:32.061489: I tensorflow/core/common_runtime/gpu/gpu_device.cc:1187]      0
2019-08-24 17:19:32.061499: I tensorflow/core/common_runtime/gpu/gpu_device.cc:1200] 0:   N
2019-08-24 17:19:32.061627: I tensorflow/stream_executor/cuda/cuda_gpu_executor.cc:1005] successful NUMA node read from SysFS had negative value (-1), but there must be at least one NUMA node, so returning NUMA node zero
2019-08-24 17:19:32.062143: I tensorflow/stream_executor/cuda/cuda_gpu_executor.cc:1005] successful NUMA node read from SysFS had negative value (-1), but there must be at least one NUMA node, so returning NUMA node zero
2019-08-24 17:19:32.062790: W tensorflow/core/common_runtime/gpu/gpu_bfc_allocator.cc:40] Overriding allow_growth setting because the TF_FORCE_GPU_ALLOW_GROWTH environment variable is set. Original config value was 0.
2019-08-24 17:19:32.062847: I tensorflow/core/common_runtime/gpu/gpu_device.cc:1326] Created TensorFlow device (/job:localhost/replica:0/task:0/device:GPU:0 with 14221 MB memory) -> physical GPU (device: 0, name: Tesla T4, pci bus id: 0000:00:04.0, compute capability: 7.5)
W0824 17:19:34.924251 140464690390912 deprecation_wrapper.py:119] From /usr/local/lib/python3.6/dist-packages/keras/optimizers.py:782: The name tf.train.Optimizer is deprecated. Please use tf.compat.v1.train.Optimizer instead.

W0824 17:19:34.937504 140464690390912 deprecation.py:323] From /usr/local/lib/python3.6/dist-packages/tensorflow/python/ops/nn_impl.py:180: add_dispatch_support.<locals>.wrapper (from tensorflow.python.ops.array_ops) is deprecated and will be removed in a future version.
Instructions for updating:
Use tf.where in 2.0, which has the same broadcast rule as np.where
Starting training
Epoch 1/20
2019-08-24 17:19:41.223881: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcudnn.so.7
2019-08-24 17:19:54.337234: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcublas.so.10.0
1000/1000 [==============================] - 607s 607ms/step - rpn_cls: 0.0643 - rpn_regr: 0.0104 - detector_cls: 0.1605 - detector_regr: 0.0962
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.83
Classifier accuracy for bounding boxes from RPN: 0.93384375
Loss RPN classifier: 0.06433113410181836
Loss RPN regression: 0.01042633028817363
Loss Detector classifier: 0.16052820887230337
Loss Detector regression: 0.09624998632771894
Elapsed time: 606.7842726707458
Total loss decreased from inf to 0.3315356595900143, saving weights
Epoch 2/20
Average number of overlapping bounding boxes from RPN = 4.83 for 1000 previous iterations
 493/1000 [=============>................] - ETA: 4:59 - rpn_cls: 0.0466 - rpn_regr: 0.0108 - detector_cls: 0.1786 - detector_regr: 0.0976Using TensorFlow backend.
Parsing annotation files
Training images per class:
{'bg': 0,
 'shape_a': 560,
 'shape_e': 532,
 'shape_eu': 552,
 'shape_i': 518,
 'shape_none': 600,
 'shape_o': 590,
 'shape_u': 600,
 'shape_ui': 598}
Num classes (including bg) = 9
Config has been written to /content/gdrive/My Drive/keras-frcnn/lips_config.pickle, and can be loaded when testing to ensure correct results
Num train samples 4120
Num val samples 430
WARNING: Logging before flag parsing goes to stderr.
W0824 17:19:29.045511 140464690390912 deprecation_wrapper.py:119] From /usr/local/lib/python3.6/dist-packages/keras/backend/tensorflow_backend.py:72: The name tf.get_default_graph is deprecated. Please use tf.compat.v1.get_default_graph instead.

W0824 17:19:29.061072 140464690390912 deprecation_wrapper.py:119] From /usr/local/lib/python3.6/dist-packages/keras/backend/tensorflow_backend.py:515: The name tf.placeholder is deprecated. Please use tf.compat.v1.placeholder instead.

W0824 17:19:29.069431 140464690390912 deprecation_wrapper.py:119] From /usr/local/lib/python3.6/dist-packages/keras/backend/tensorflow_backend.py:4048: The name tf.random_uniform is deprecated. Please use tf.random.uniform instead.

W0824 17:19:29.095561 140464690390912 deprecation_wrapper.py:119] From /usr/local/lib/python3.6/dist-packages/keras/backend/tensorflow_backend.py:1897: The name tf.nn.fused_batch_norm is deprecated. Please use tf.compat.v1.nn.fused_batch_norm instead.

W0824 17:19:29.097124 140464690390912 deprecation_wrapper.py:119] From /usr/local/lib/python3.6/dist-packages/keras/backend/tensorflow_backend.py:3878: The name tf.nn.max_pool is deprecated. Please use tf.nn.max_pool2d instead.

W0824 17:19:30.267974 140464690390912 deprecation_wrapper.py:119] From /usr/local/lib/python3.6/dist-packages/keras/backend/tensorflow_backend.py:4025: The name tf.random_normal is deprecated. Please use tf.random.normal instead.

W0824 17:19:30.306995 140464690390912 deprecation_wrapper.py:119] From /content/gdrive/My Drive/keras-frcnn/keras_frcnn/RoiPoolingConv.py:105: The name tf.image.resize_images is deprecated. Please use tf.image.resize instead.

W0824 17:19:31.259393 140464690390912 deprecation_wrapper.py:119] From /usr/local/lib/python3.6/dist-packages/keras/backend/tensorflow_backend.py:3882: The name tf.nn.avg_pool is deprecated. Please use tf.nn.avg_pool2d instead.

loading weights from /content/gdrive/My Drive/keras-frcnn/lip_weight.hdf5
W0824 17:19:31.872316 140464690390912 deprecation_wrapper.py:119] From /usr/local/lib/python3.6/dist-packages/keras/backend/tensorflow_backend.py:172: The name tf.get_default_session is deprecated. Please use tf.compat.v1.get_default_session instead.

2019-08-24 17:19:31.877409: I tensorflow/core/platform/profile_utils/cpu_utils.cc:94] CPU Frequency: 2300000000 Hz
2019-08-24 17:19:31.877763: I tensorflow/compiler/xla/service/service.cc:168] XLA service 0x82b7d40 executing computations on platform Host. Devices:
2019-08-24 17:19:31.877798: I tensorflow/compiler/xla/service/service.cc:175]   StreamExecutor device (0): <undefined>, <undefined>
2019-08-24 17:19:31.880014: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcuda.so.1
2019-08-24 17:19:32.048155: I tensorflow/stream_executor/cuda/cuda_gpu_executor.cc:1005] successful NUMA node read from SysFS had negative value (-1), but there must be at least one NUMA node, so returning NUMA node zero
2019-08-24 17:19:32.048870: I tensorflow/compiler/xla/service/service.cc:168] XLA service 0x8750380 executing computations on platform CUDA. Devices:
2019-08-24 17:19:32.048904: I tensorflow/compiler/xla/service/service.cc:175]   StreamExecutor device (0): Tesla T4, Compute Capability 7.5
2019-08-24 17:19:32.049118: I tensorflow/stream_executor/cuda/cuda_gpu_executor.cc:1005] successful NUMA node read from SysFS had negative value (-1), but there must be at least one NUMA node, so returning NUMA node zero
2019-08-24 17:19:32.049663: I tensorflow/core/common_runtime/gpu/gpu_device.cc:1640] Found device 0 with properties:
name: Tesla T4 major: 7 minor: 5 memoryClockRate(GHz): 1.59
pciBusID: 0000:00:04.0
2019-08-24 17:19:32.050043: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcudart.so.10.0
2019-08-24 17:19:32.051358: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcublas.so.10.0
2019-08-24 17:19:32.052815: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcufft.so.10.0
2019-08-24 17:19:32.053191: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcurand.so.10.0
2019-08-24 17:19:32.054771: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcusolver.so.10.0
2019-08-24 17:19:32.055922: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcusparse.so.10.0
2019-08-24 17:19:32.059348: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcudnn.so.7
2019-08-24 17:19:32.059482: I tensorflow/stream_executor/cuda/cuda_gpu_executor.cc:1005] successful NUMA node read from SysFS had negative value (-1), but there must be at least one NUMA node, so returning NUMA node zero
2019-08-24 17:19:32.059993: I tensorflow/stream_executor/cuda/cuda_gpu_executor.cc:1005] successful NUMA node read from SysFS had negative value (-1), but there must be at least one NUMA node, so returning NUMA node zero
2019-08-24 17:19:32.060453: I tensorflow/core/common_runtime/gpu/gpu_device.cc:1763] Adding visible gpu devices: 0
2019-08-24 17:19:32.060512: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcudart.so.10.0
2019-08-24 17:19:32.061463: I tensorflow/core/common_runtime/gpu/gpu_device.cc:1181] Device interconnect StreamExecutor with strength 1 edge matrix:
2019-08-24 17:19:32.061489: I tensorflow/core/common_runtime/gpu/gpu_device.cc:1187]      0
2019-08-24 17:19:32.061499: I tensorflow/core/common_runtime/gpu/gpu_device.cc:1200] 0:   N
2019-08-24 17:19:32.061627: I tensorflow/stream_executor/cuda/cuda_gpu_executor.cc:1005] successful NUMA node read from SysFS had negative value (-1), but there must be at least one NUMA node, so returning NUMA node zero
2019-08-24 17:19:32.062143: I tensorflow/stream_executor/cuda/cuda_gpu_executor.cc:1005] successful NUMA node read from SysFS had negative value (-1), but there must be at least one NUMA node, so returning NUMA node zero
2019-08-24 17:19:32.062790: W tensorflow/core/common_runtime/gpu/gpu_bfc_allocator.cc:40] Overriding allow_growth setting because the TF_FORCE_GPU_ALLOW_GROWTH environment variable is set. Original config value was 0.
2019-08-24 17:19:32.062847: I tensorflow/core/common_runtime/gpu/gpu_device.cc:1326] Created TensorFlow device (/job:localhost/replica:0/task:0/device:GPU:0 with 14221 MB memory) -> physical GPU (device: 0, name: Tesla T4, pci bus id: 0000:00:04.0, compute capability: 7.5)
W0824 17:19:34.924251 140464690390912 deprecation_wrapper.py:119] From /usr/local/lib/python3.6/dist-packages/keras/optimizers.py:782: The name tf.train.Optimizer is deprecated. Please use tf.compat.v1.train.Optimizer instead.

W0824 17:19:34.937504 140464690390912 deprecation.py:323] From /usr/local/lib/python3.6/dist-packages/tensorflow/python/ops/nn_impl.py:180: add_dispatch_support.<locals>.wrapper (from tensorflow.python.ops.array_ops) is deprecated and will be removed in a future version.
Instructions for updating:
Use tf.where in 2.0, which has the same broadcast rule as np.where
Starting training
Epoch 1/20
2019-08-24 17:19:41.223881: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcudnn.so.7
2019-08-24 17:19:54.337234: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcublas.so.10.0
1000/1000 [==============================] - 607s 607ms/step - rpn_cls: 0.0643 - rpn_regr: 0.0104 - detector_cls: 0.1605 - detector_regr: 0.0962
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.83
Classifier accuracy for bounding boxes from RPN: 0.93384375
Loss RPN classifier: 0.06433113410181836
Loss RPN regression: 0.01042633028817363
Loss Detector classifier: 0.16052820887230337
Loss Detector regression: 0.09624998632771894
Elapsed time: 606.7842726707458
Total loss decreased from inf to 0.3315356595900143, saving weights
Epoch 2/20
Average number of overlapping bounding boxes from RPN = 4.83 for 1000 previous iterations
1000/1000 [==============================] - 593s 593ms/step - rpn_cls: 0.0674 - rpn_regr: 0.0110 - detector_cls: 0.1735 - detector_regr: 0.0958
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.925
Classifier accuracy for bounding boxes from RPN: 0.92803125
Loss RPN classifier: 0.06741742639188211
Loss RPN regression: 0.010961576126886939
Loss Detector classifier: 0.17350951494462788
Loss Detector regression: 0.09578112849686295
Elapsed time: 613.5073120594025
Epoch 3/20
Average number of overlapping bounding boxes from RPN = 4.925 for 1000 previous iterations
1000/1000 [==============================] - 593s 593ms/step - rpn_cls: 0.0674 - rpn_regr: 0.0110 - detector_cls: 0.1735 - detector_regr: 0.0958
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.925
Classifier accuracy for bounding boxes from RPN: 0.92803125
Loss RPN classifier: 0.06741742639188211
Loss RPN regression: 0.010961576126886939
Loss Detector classifier: 0.17350951494462788
Loss Detector regression: 0.09578112849686295
Elapsed time: 613.5073120594025
Epoch 3/20
Average number of overlapping bounding boxes from RPN = 4.925 for 1000 previous iterations
1000/1000 [==============================] - 589s 589ms/step - rpn_cls: 0.0945 - rpn_regr: 0.0104 - detector_cls: 0.1687 - detector_regr: 0.0930
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.714
Classifier accuracy for bounding boxes from RPN: 0.92903125
Loss RPN classifier: 0.09448530852360941
Loss RPN regression: 0.010433797801073523
Loss Detector classifier: 0.16868579906923697
Loss Detector regression: 0.09299889776436612
Elapsed time: 589.4226114749908
Epoch 4/20
Average number of overlapping bounding boxes from RPN = 4.714 for 1000 previous iterations
1000/1000 [==============================] - 589s 589ms/step - rpn_cls: 0.0945 - rpn_regr: 0.0104 - detector_cls: 0.1687 - detector_regr: 0.0930
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.714
Classifier accuracy for bounding boxes from RPN: 0.92903125
Loss RPN classifier: 0.09448530852360941
Loss RPN regression: 0.010433797801073523
Loss Detector classifier: 0.16868579906923697
Loss Detector regression: 0.09299889776436612
Elapsed time: 589.4226114749908
Epoch 4/20
Average number of overlapping bounding boxes from RPN = 4.714 for 1000 previous iterations
1000/1000 [==============================] - 578s 578ms/step - rpn_cls: 0.0544 - rpn_regr: 0.0111 - detector_cls: 0.1572 - detector_regr: 0.0941
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.715
Classifier accuracy for bounding boxes from RPN: 0.9339375
Loss RPN classifier: 0.0543821458206303
Loss RPN regression: 0.011141120896834764
Loss Detector classifier: 0.15724397791083902
Loss Detector regression: 0.09407750365277752
Elapsed time: 578.4112334251404
Total loss decreased from 0.3315356595900143 to 0.3168447482810816, saving weights
1000/1000 [==============================] - 578s 578ms/step - rpn_cls: 0.0544 - rpn_regr: 0.0111 - detector_cls: 0.1572 - detector_regr: 0.0941
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.715
Classifier accuracy for bounding boxes from RPN: 0.9339375
Loss RPN classifier: 0.0543821458206303
Loss RPN regression: 0.011141120896834764
Loss Detector classifier: 0.15724397791083902
Loss Detector regression: 0.09407750365277752
Elapsed time: 578.4112334251404
Total loss decreased from 0.3315356595900143 to 0.3168447482810816, saving weights
Epoch 5/20
Average number of overlapping bounding boxes from RPN = 4.715 for 1000 previous iterations
Epoch 5/20
Average number of overlapping bounding boxes from RPN = 4.715 for 1000 previous iterations
1000/1000 [==============================] - 581s 581ms/step - rpn_cls: 0.0304 - rpn_regr: 0.0097 - detector_cls: 0.1527 - detector_regr: 0.0858
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.708
Classifier accuracy for bounding boxes from RPN: 0.9354375
Loss RPN classifier: 0.030374700858906176
Loss RPN regression: 0.009680742358319549
Loss Detector classifier: 0.15274407316558064
Loss Detector regression: 0.08582254274375736
Elapsed time: 583.2294237613678
Total loss decreased from 0.3168447482810816 to 0.27862205912656374, saving weights
1000/1000 [==============================] - 581s 581ms/step - rpn_cls: 0.0304 - rpn_regr: 0.0097 - detector_cls: 0.1527 - detector_regr: 0.0858
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.708
Classifier accuracy for bounding boxes from RPN: 0.9354375
Loss RPN classifier: 0.030374700858906176
Loss RPN regression: 0.009680742358319549
Loss Detector classifier: 0.15274407316558064
Loss Detector regression: 0.08582254274375736
Elapsed time: 583.2294237613678
Total loss decreased from 0.3168447482810816 to 0.27862205912656374, saving weights
Epoch 6/20
Average number of overlapping bounding boxes from RPN = 4.708 for 1000 previous iterations
Epoch 6/20
Average number of overlapping bounding boxes from RPN = 4.708 for 1000 previous iterations
 926/1000 [==========================>...] - ETA: 43s - rpn_cls: 0.0964 - rpn_regr: 0.0100 - detector_cls: 0.1579 - detector_regr: 0.0920Exception: 'a' cannot be empty unless no samples are taken
Exception: 'a' cannot be empty unless no samples are taken
 999/1000 [============================>.] - ETA: 0s - rpn_cls: 0.0937 - rpn_regr: 0.0101 - detector_cls: 0.1591 - detector_regr: 0.0922Average number of overlapping bounding boxes from RPN = 4.623 for 1000 previous iterations
 999/1000 [============================>.] - ETA: 0s - rpn_cls: 0.0937 - rpn_regr: 0.0101 - detector_cls: 0.1591 - detector_regr: 0.0922Average number of overlapping bounding boxes from RPN = 4.623 for 1000 previous iterations
1000/1000 [==============================] - 585s 585ms/step - rpn_cls: 0.0936 - rpn_regr: 0.0101 - detector_cls: 0.1590 - detector_regr: 0.0921
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.624375624375625
Classifier accuracy for bounding boxes from RPN: 0.93325
Loss RPN classifier: 0.09360856310731065
Loss RPN regression: 0.010138179298897739
Loss Detector classifier: 0.1590372465820983
Loss Detector regression: 0.09212062139017507
Elapsed time: 586.940149307251
Epoch 7/20
1000/1000 [==============================] - 585s 585ms/step - rpn_cls: 0.0936 - rpn_regr: 0.0101 - detector_cls: 0.1590 - detector_regr: 0.0921
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.624375624375625
Classifier accuracy for bounding boxes from RPN: 0.93325
Loss RPN classifier: 0.09360856310731065
Loss RPN regression: 0.010138179298897739
Loss Detector classifier: 0.1590372465820983
Loss Detector regression: 0.09212062139017507
Elapsed time: 586.940149307251
Epoch 7/20
 999/1000 [============================>.] - ETA: 0s - rpn_cls: 0.0409 - rpn_regr: 0.0100 - detector_cls: 0.1529 - detector_regr: 0.0954Average number of overlapping bounding boxes from RPN = 4.752 for 1000 previous iterations
 999/1000 [============================>.] - ETA: 0s - rpn_cls: 0.0409 - rpn_regr: 0.0100 - detector_cls: 0.1529 - detector_regr: 0.0954Average number of overlapping bounding boxes from RPN = 4.752 for 1000 previous iterations
1000/1000 [==============================] - 582s 582ms/step - rpn_cls: 0.0408 - rpn_regr: 0.0100 - detector_cls: 0.1530 - detector_regr: 0.0953
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.746
Classifier accuracy for bounding boxes from RPN: 0.93334375
Loss RPN classifier: 0.04083029688640245
Loss RPN regression: 0.010023641262538149
Loss Detector classifier: 0.15302261526044458
Loss Detector regression: 0.0953452697917819
Elapsed time: 582.3285467624664
Epoch 8/20
1000/1000 [==============================] - 582s 582ms/step - rpn_cls: 0.0408 - rpn_regr: 0.0100 - detector_cls: 0.1530 - detector_regr: 0.0953
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.746
Classifier accuracy for bounding boxes from RPN: 0.93334375
Loss RPN classifier: 0.04083029688640245
Loss RPN regression: 0.010023641262538149
Loss Detector classifier: 0.15302261526044458
Loss Detector regression: 0.0953452697917819
Elapsed time: 582.3285467624664
Epoch 8/20
 999/1000 [============================>.] - ETA: 0s - rpn_cls: 0.0363 - rpn_regr: 0.0094 - detector_cls: 0.1580 - detector_regr: 0.0880Average number of overlapping bounding boxes from RPN = 4.795 for 1000 previous iterations
 999/1000 [============================>.] - ETA: 0s - rpn_cls: 0.0363 - rpn_regr: 0.0094 - detector_cls: 0.1580 - detector_regr: 0.0880Average number of overlapping bounding boxes from RPN = 4.795 for 1000 previous iterations
1000/1000 [==============================] - 581s 581ms/step - rpn_cls: 0.0362 - rpn_regr: 0.0094 - detector_cls: 0.1579 - detector_regr: 0.0880
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.801
Classifier accuracy for bounding boxes from RPN: 0.9345625
Loss RPN classifier: 0.036237243177712104
Loss RPN regression: 0.009394308665388961
Loss Detector classifier: 0.15788377680629492
Loss Detector regression: 0.08804123476101086
Elapsed time: 581.203773021698
Epoch 9/20
1000/1000 [==============================] - 581s 581ms/step - rpn_cls: 0.0362 - rpn_regr: 0.0094 - detector_cls: 0.1579 - detector_regr: 0.0880
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.801
Classifier accuracy for bounding boxes from RPN: 0.9345625
Loss RPN classifier: 0.036237243177712104
Loss RPN regression: 0.009394308665388961
Loss Detector classifier: 0.15788377680629492
Loss Detector regression: 0.08804123476101086
Elapsed time: 581.203773021698
Epoch 9/20
 999/1000 [============================>.] - ETA: 0s - rpn_cls: 0.0680 - rpn_regr: 0.0098 - detector_cls: 0.1576 - detector_regr: 0.0899Average number of overlapping bounding boxes from RPN = 4.804 for 1000 previous iterations
 999/1000 [============================>.] - ETA: 0s - rpn_cls: 0.0680 - rpn_regr: 0.0098 - detector_cls: 0.1576 - detector_regr: 0.0899Average number of overlapping bounding boxes from RPN = 4.804 for 1000 previous iterations
1000/1000 [==============================] - 581s 581ms/step - rpn_cls: 0.0679 - rpn_regr: 0.0098 - detector_cls: 0.1576 - detector_regr: 0.0899
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.801
Classifier accuracy for bounding boxes from RPN: 0.93209375
Loss RPN classifier: 0.06789948118539309
Loss RPN regression: 0.009770858683448751
Loss Detector classifier: 0.15756188617553563
Loss Detector regression: 0.08991256112721749
Elapsed time: 580.8748035430908
Epoch 10/20
1000/1000 [==============================] - 581s 581ms/step - rpn_cls: 0.0679 - rpn_regr: 0.0098 - detector_cls: 0.1576 - detector_regr: 0.0899
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.801
Classifier accuracy for bounding boxes from RPN: 0.93209375
Loss RPN classifier: 0.06789948118539309
Loss RPN regression: 0.009770858683448751
Loss Detector classifier: 0.15756188617553563
Loss Detector regression: 0.08991256112721749
Elapsed time: 580.8748035430908
Epoch 10/20
 999/1000 [============================>.] - ETA: 0s - rpn_cls: 0.0776 - rpn_regr: 0.0093 - detector_cls: 0.1747 - detector_regr: 0.0876Average number of overlapping bounding boxes from RPN = 5.009 for 1000 previous iterations
 999/1000 [============================>.] - ETA: 0s - rpn_cls: 0.0776 - rpn_regr: 0.0093 - detector_cls: 0.1747 - detector_regr: 0.0876Average number of overlapping bounding boxes from RPN = 5.009 for 1000 previous iterations
1000/1000 [==============================] - 583s 583ms/step - rpn_cls: 0.0775 - rpn_regr: 0.0093 - detector_cls: 0.1746 - detector_regr: 0.0875
Mean number of bounding boxes from RPN overlapping ground truth boxes: 5.01
Classifier accuracy for bounding boxes from RPN: 0.92703125
Loss RPN classifier: 0.07752880576317081
Loss RPN regression: 0.009328088896356349
Loss Detector classifier: 0.17460629642289133
Loss Detector regression: 0.08749426144594327
Elapsed time: 583.4964411258698
Epoch 11/20
1000/1000 [==============================] - 583s 583ms/step - rpn_cls: 0.0775 - rpn_regr: 0.0093 - detector_cls: 0.1746 - detector_regr: 0.0875
Mean number of bounding boxes from RPN overlapping ground truth boxes: 5.01
Classifier accuracy for bounding boxes from RPN: 0.92703125
Loss RPN classifier: 0.07752880576317081
Loss RPN regression: 0.009328088896356349
Loss Detector classifier: 0.17460629642289133
Loss Detector regression: 0.08749426144594327
Elapsed time: 583.4964411258698
Epoch 11/20
 999/1000 [============================>.] - ETA: 0s - rpn_cls: 0.0562 - rpn_regr: 0.0099 - detector_cls: 0.1533 - detector_regr: 0.0873Average number of overlapping bounding boxes from RPN = 4.829 for 1000 previous iterations
 999/1000 [============================>.] - ETA: 0s - rpn_cls: 0.0562 - rpn_regr: 0.0099 - detector_cls: 0.1533 - detector_regr: 0.0873Average number of overlapping bounding boxes from RPN = 4.829 for 1000 previous iterations
1000/1000 [==============================] - 578s 578ms/step - rpn_cls: 0.0562 - rpn_regr: 0.0099 - detector_cls: 0.1533 - detector_regr: 0.0873
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.829
Classifier accuracy for bounding boxes from RPN: 0.93490625
Loss RPN classifier: 0.05619200005382606
Loss RPN regression: 0.00989991170882422
Loss Detector classifier: 0.1532880294751376
Loss Detector regression: 0.08725677641388029
Elapsed time: 577.5905997753143
Epoch 12/20
1000/1000 [==============================] - 578s 578ms/step - rpn_cls: 0.0562 - rpn_regr: 0.0099 - detector_cls: 0.1533 - detector_regr: 0.0873
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.829
Classifier accuracy for bounding boxes from RPN: 0.93490625
Loss RPN classifier: 0.05619200005382606
Loss RPN regression: 0.00989991170882422
Loss Detector classifier: 0.1532880294751376
Loss Detector regression: 0.08725677641388029
Elapsed time: 577.5905997753143
Epoch 12/20
 999/1000 [============================>.] - ETA: 0s - rpn_cls: 0.0091 - rpn_regr: 0.0092 - detector_cls: 0.1535 - detector_regr: 0.0832Average number of overlapping bounding boxes from RPN = 4.897 for 1000 previous iterations
 999/1000 [============================>.] - ETA: 0s - rpn_cls: 0.0091 - rpn_regr: 0.0092 - detector_cls: 0.1535 - detector_regr: 0.0832Average number of overlapping bounding boxes from RPN = 4.897 for 1000 previous iterations
1000/1000 [==============================] - 576s 576ms/step - rpn_cls: 0.0091 - rpn_regr: 0.0092 - detector_cls: 0.1536 - detector_regr: 0.0832
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.902
Classifier accuracy for bounding boxes from RPN: 0.93659375
Loss RPN classifier: 0.009083191059521337
Loss RPN regression: 0.009195538518168178
Loss Detector classifier: 0.15363640448916704
Loss Detector regression: 0.08315791266411543
Elapsed time: 576.4818379878998
Total loss decreased from 0.27862205912656374 to 0.255073046730972, saving weights
1000/1000 [==============================] - 576s 576ms/step - rpn_cls: 0.0091 - rpn_regr: 0.0092 - detector_cls: 0.1536 - detector_regr: 0.0832
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.902
Classifier accuracy for bounding boxes from RPN: 0.93659375
Loss RPN classifier: 0.009083191059521337
Loss RPN regression: 0.009195538518168178
Loss Detector classifier: 0.15363640448916704
Loss Detector regression: 0.08315791266411543
Elapsed time: 576.4818379878998
Total loss decreased from 0.27862205912656374 to 0.255073046730972, saving weights
Epoch 13/20
Epoch 13/20
 999/1000 [============================>.] - ETA: 0s - rpn_cls: 0.0379 - rpn_regr: 0.0093 - detector_cls: 0.1549 - detector_regr: 0.0856Average number of overlapping bounding boxes from RPN = 4.941 for 1000 previous iterations
 999/1000 [============================>.] - ETA: 0s - rpn_cls: 0.0379 - rpn_regr: 0.0093 - detector_cls: 0.1549 - detector_regr: 0.0856Average number of overlapping bounding boxes from RPN = 4.941 for 1000 previous iterations
1000/1000 [==============================] - 577s 577ms/step - rpn_cls: 0.0378 - rpn_regr: 0.0093 - detector_cls: 0.1549 - detector_regr: 0.0856
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.935
Classifier accuracy for bounding boxes from RPN: 0.93471875
Loss RPN classifier: 0.03782229253090534
Loss RPN regression: 0.00934852040195983
Loss Detector classifier: 0.1549440229656175
Loss Detector regression: 0.0856289753948804
Elapsed time: 579.3444745540619
Epoch 14/20
1000/1000 [==============================] - 577s 577ms/step - rpn_cls: 0.0378 - rpn_regr: 0.0093 - detector_cls: 0.1549 - detector_regr: 0.0856
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.935
Classifier accuracy for bounding boxes from RPN: 0.93471875
Loss RPN classifier: 0.03782229253090534
Loss RPN regression: 0.00934852040195983
Loss Detector classifier: 0.1549440229656175
Loss Detector regression: 0.0856289753948804
Elapsed time: 579.3444745540619
Epoch 14/20
 999/1000 [============================>.] - ETA: 0s - rpn_cls: 0.0248 - rpn_regr: 0.0091 - detector_cls: 0.1509 - detector_regr: 0.0860Average number of overlapping bounding boxes from RPN = 4.761 for 1000 previous iterations
 999/1000 [============================>.] - ETA: 0s - rpn_cls: 0.0248 - rpn_regr: 0.0091 - detector_cls: 0.1509 - detector_regr: 0.0860Average number of overlapping bounding boxes from RPN = 4.761 for 1000 previous iterations
1000/1000 [==============================] - 579s 579ms/step - rpn_cls: 0.0248 - rpn_regr: 0.0091 - detector_cls: 0.1508 - detector_regr: 0.0860
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.762
Classifier accuracy for bounding boxes from RPN: 0.9349375
Loss RPN classifier: 0.024813799113742235
Loss RPN regression: 0.009139857770984236
Loss Detector classifier: 0.15081148265860975
Loss Detector regression: 0.08595627579768188
Elapsed time: 579.410153388977
Epoch 15/20
1000/1000 [==============================] - 579s 579ms/step - rpn_cls: 0.0248 - rpn_regr: 0.0091 - detector_cls: 0.1508 - detector_regr: 0.0860
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.762
Classifier accuracy for bounding boxes from RPN: 0.9349375
Loss RPN classifier: 0.024813799113742235
Loss RPN regression: 0.009139857770984236
Loss Detector classifier: 0.15081148265860975
Loss Detector regression: 0.08595627579768188
Elapsed time: 579.410153388977
Epoch 15/20
 999/1000 [============================>.] - ETA: 0s - rpn_cls: 0.0169 - rpn_regr: 0.0092 - detector_cls: 0.1530 - detector_regr: 0.0843Average number of overlapping bounding boxes from RPN = 5.022 for 1000 previous iterations
 999/1000 [============================>.] - ETA: 0s - rpn_cls: 0.0169 - rpn_regr: 0.0092 - detector_cls: 0.1530 - detector_regr: 0.0843Average number of overlapping bounding boxes from RPN = 5.022 for 1000 previous iterations
1000/1000 [==============================] - 574s 574ms/step - rpn_cls: 0.0169 - rpn_regr: 0.0092 - detector_cls: 0.1530 - detector_regr: 0.0843
Mean number of bounding boxes from RPN overlapping ground truth boxes: 5.023
Classifier accuracy for bounding boxes from RPN: 0.9341875
Loss RPN classifier: 0.01687533922040613
Loss RPN regression: 0.00923105049377773
Loss Detector classifier: 0.15296667452715337
Loss Detector regression: 0.08430431489553303
Elapsed time: 573.9699490070343
Epoch 16/20
1000/1000 [==============================] - 574s 574ms/step - rpn_cls: 0.0169 - rpn_regr: 0.0092 - detector_cls: 0.1530 - detector_regr: 0.0843
Mean number of bounding boxes from RPN overlapping ground truth boxes: 5.023
Classifier accuracy for bounding boxes from RPN: 0.9341875
Loss RPN classifier: 0.01687533922040613
Loss RPN regression: 0.00923105049377773
Loss Detector classifier: 0.15296667452715337
Loss Detector regression: 0.08430431489553303
Elapsed time: 573.9699490070343
Epoch 16/20
 999/1000 [============================>.] - ETA: 0s - rpn_cls: 0.0624 - rpn_regr: 0.0092 - detector_cls: 0.1635 - detector_regr: 0.0816Average number of overlapping bounding boxes from RPN = 5.156 for 1000 previous iterations
 999/1000 [============================>.] - ETA: 0s - rpn_cls: 0.0624 - rpn_regr: 0.0092 - detector_cls: 0.1635 - detector_regr: 0.0816Average number of overlapping bounding boxes from RPN = 5.156 for 1000 previous iterations
1000/1000 [==============================] - 579s 579ms/step - rpn_cls: 0.0623 - rpn_regr: 0.0092 - detector_cls: 0.1634 - detector_regr: 0.0815
Mean number of bounding boxes from RPN overlapping ground truth boxes: 5.153
Classifier accuracy for bounding boxes from RPN: 0.93140625
Loss RPN classifier: 0.062306248389626534
Loss RPN regression: 0.009220354881537787
Loss Detector classifier: 0.16341227300837635
Loss Detector regression: 0.08153667521569878
Elapsed time: 578.5381944179535
Epoch 17/20
1000/1000 [==============================] - 579s 579ms/step - rpn_cls: 0.0623 - rpn_regr: 0.0092 - detector_cls: 0.1634 - detector_regr: 0.0815
Mean number of bounding boxes from RPN overlapping ground truth boxes: 5.153
Classifier accuracy for bounding boxes from RPN: 0.93140625
Loss RPN classifier: 0.062306248389626534
Loss RPN regression: 0.009220354881537787
Loss Detector classifier: 0.16341227300837635
Loss Detector regression: 0.08153667521569878
Elapsed time: 578.5381944179535
Epoch 17/20
 999/1000 [============================>.] - ETA: 0s - rpn_cls: 0.0363 - rpn_regr: 0.0096 - detector_cls: 0.1723 - detector_regr: 0.0854Average number of overlapping bounding boxes from RPN = 5.183 for 1000 previous iterations
 999/1000 [============================>.] - ETA: 0s - rpn_cls: 0.0363 - rpn_regr: 0.0096 - detector_cls: 0.1723 - detector_regr: 0.0854Average number of overlapping bounding boxes from RPN = 5.183 for 1000 previous iterations
1000/1000 [==============================] - 579s 579ms/step - rpn_cls: 0.0362 - rpn_regr: 0.0097 - detector_cls: 0.1724 - detector_regr: 0.0856
Mean number of bounding boxes from RPN overlapping ground truth boxes: 5.182
Classifier accuracy for bounding boxes from RPN: 0.92565625
Loss RPN classifier: 0.0362401628012544
Loss RPN regression: 0.00966309686326713
Loss Detector classifier: 0.17239415664039553
Loss Detector regression: 0.08563737028185278
Elapsed time: 578.78422498703
Epoch 18/20
1000/1000 [==============================] - 579s 579ms/step - rpn_cls: 0.0362 - rpn_regr: 0.0097 - detector_cls: 0.1724 - detector_regr: 0.0856
Mean number of bounding boxes from RPN overlapping ground truth boxes: 5.182
Classifier accuracy for bounding boxes from RPN: 0.92565625
Loss RPN classifier: 0.0362401628012544
Loss RPN regression: 0.00966309686326713
Loss Detector classifier: 0.17239415664039553
Loss Detector regression: 0.08563737028185278
Elapsed time: 578.78422498703
Epoch 18/20
 999/1000 [============================>.] - ETA: 0s - rpn_cls: 0.0622 - rpn_regr: 0.0087 - detector_cls: 0.1603 - detector_regr: 0.0818Average number of overlapping bounding boxes from RPN = 5.095 for 1000 previous iterations
 999/1000 [============================>.] - ETA: 0s - rpn_cls: 0.0622 - rpn_regr: 0.0087 - detector_cls: 0.1603 - detector_regr: 0.0818Average number of overlapping bounding boxes from RPN = 5.095 for 1000 previous iterations
1000/1000 [==============================] - 577s 577ms/step - rpn_cls: 0.0621 - rpn_regr: 0.0087 - detector_cls: 0.1603 - detector_regr: 0.0818
Mean number of bounding boxes from RPN overlapping ground truth boxes: 5.099
Classifier accuracy for bounding boxes from RPN: 0.932875
Loss RPN classifier: 0.06209307102752894
Loss RPN regression: 0.008728487797096023
Loss Detector classifier: 0.16025365704717115
Loss Detector regression: 0.081788202223368
Elapsed time: 576.9003746509552
Epoch 19/20
1000/1000 [==============================] - 577s 577ms/step - rpn_cls: 0.0621 - rpn_regr: 0.0087 - detector_cls: 0.1603 - detector_regr: 0.0818
Mean number of bounding boxes from RPN overlapping ground truth boxes: 5.099
Classifier accuracy for bounding boxes from RPN: 0.932875
Loss RPN classifier: 0.06209307102752894
Loss RPN regression: 0.008728487797096023
Loss Detector classifier: 0.16025365704717115
Loss Detector regression: 0.081788202223368
Elapsed time: 576.9003746509552
Epoch 19/20
 999/1000 [============================>.] - ETA: 0s - rpn_cls: 0.0182 - rpn_regr: 0.0085 - detector_cls: 0.1517 - detector_regr: 0.0797Average number of overlapping bounding boxes from RPN = 4.99 for 1000 previous iterations
 999/1000 [============================>.] - ETA: 0s - rpn_cls: 0.0182 - rpn_regr: 0.0085 - detector_cls: 0.1517 - detector_regr: 0.0797Average number of overlapping bounding boxes from RPN = 4.99 for 1000 previous iterations
1000/1000 [==============================] - 572s 572ms/step - rpn_cls: 0.0182 - rpn_regr: 0.0085 - detector_cls: 0.1516 - detector_regr: 0.0797
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.989
Classifier accuracy for bounding boxes from RPN: 0.93403125
Loss RPN classifier: 0.018179455776428967
Loss RPN regression: 0.008521241408579953
Loss Detector classifier: 0.15159292028099297
Loss Detector regression: 0.07967844884935767
Elapsed time: 571.7883970737457
Epoch 20/20
1000/1000 [==============================] - 572s 572ms/step - rpn_cls: 0.0182 - rpn_regr: 0.0085 - detector_cls: 0.1516 - detector_regr: 0.0797
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.989
Classifier accuracy for bounding boxes from RPN: 0.93403125
Loss RPN classifier: 0.018179455776428967
Loss RPN regression: 0.008521241408579953
Loss Detector classifier: 0.15159292028099297
Loss Detector regression: 0.07967844884935767
Elapsed time: 571.7883970737457
Epoch 20/20
 444/1000 [============>.................] - ETA: 5:17 - rpn_cls: 0.0198 - rpn_regr: 0.0088 - detector_cls: 0.1520 - detector_regr: 0.0815Exception: 'a' cannot be empty unless no samples are taken
Exception: 'a' cannot be empty unless no samples are taken
 998/1000 [============================>.] - ETA: 1s - rpn_cls: 0.0257 - rpn_regr: 0.0085 - detector_cls: 0.1559 - detector_regr: 0.0809Average number of overlapping bounding boxes from RPN = 5.146 for 1000 previous iterations
 998/1000 [============================>.] - ETA: 1s - rpn_cls: 0.0257 - rpn_regr: 0.0085 - detector_cls: 0.1559 - detector_regr: 0.0809Average number of overlapping bounding boxes from RPN = 5.146 for 1000 previous iterations
1000/1000 [==============================] - 573s 573ms/step - rpn_cls: 0.0256 - rpn_regr: 0.0086 - detector_cls: 0.1558 - detector_regr: 0.0809
Mean number of bounding boxes from RPN overlapping ground truth boxes: 5.147852147852148
Classifier accuracy for bounding boxes from RPN: 0.933125
Loss RPN classifier: 0.025624915768343873
Loss RPN regression: 0.008561410036461893
Loss Detector classifier: 0.15578309240425006
Loss Detector regression: 0.08089214456267654
Elapsed time: 572.6757299900055
Training complete, exiting.
1000/1000 [==============================] - 573s 573ms/step - rpn_cls: 0.0256 - rpn_regr: 0.0086 - detector_cls: 0.1558 - detector_regr: 0.0809
Mean number of bounding boxes from RPN overlapping ground truth boxes: 5.147852147852148
Classifier accuracy for bounding boxes from RPN: 0.933125
Loss RPN classifier: 0.025624915768343873
Loss RPN regression: 0.008561410036461893
Loss Detector classifier: 0.15578309240425006
Loss Detector regression: 0.08089214456267654
Elapsed time: 572.6757299900055
Training complete, exiting.

# 3차시도
# krcnn 트레이닝 -> 성공
# hdf5 : lips_weight.hdf5
# config : lips_config.pickle
# 에폭 : 20
# 2019. 08. 25
Using TensorFlow backend.
Parsing annotation files
Training images per class:
{'bg': 0,
 'shape_a': 560,
 'shape_e': 532,
 'shape_eu': 552,
 'shape_i': 518,
 'shape_none': 600,
 'shape_o': 590,
 'shape_u': 600,
 'shape_ui': 598}
Num classes (including bg) = 9
Config has been written to /content/gdrive/My Drive/keras-frcnn/lips_config.pickle, and can be loaded when testing to ensure correct results
Num train samples 4120
Num val samples 430
WARNING: Logging before flag parsing goes to stderr.
W0824 12:22:42.477009 140444082550656 deprecation_wrapper.py:119] From /usr/local/lib/python3.6/dist-packages/keras/backend/tensorflow_backend.py:72: The name tf.get_default_graph is deprecated. Please use tf.compat.v1.get_default_graph instead.

W0824 12:22:42.487824 140444082550656 deprecation_wrapper.py:119] From /usr/local/lib/python3.6/dist-packages/keras/backend/tensorflow_backend.py:515: The name tf.placeholder is deprecated. Please use tf.compat.v1.placeholder instead.

W0824 12:22:42.492312 140444082550656 deprecation_wrapper.py:119] From /usr/local/lib/python3.6/dist-packages/keras/backend/tensorflow_backend.py:4048: The name tf.random_uniform is deprecated. Please use tf.random.uniform instead.

W0824 12:22:42.516511 140444082550656 deprecation_wrapper.py:119] From /usr/local/lib/python3.6/dist-packages/keras/backend/tensorflow_backend.py:1897: The name tf.nn.fused_batch_norm is deprecated. Please use tf.compat.v1.nn.fused_batch_norm instead.

W0824 12:22:42.518006 140444082550656 deprecation_wrapper.py:119] From /usr/local/lib/python3.6/dist-packages/keras/backend/tensorflow_backend.py:3878: The name tf.nn.max_pool is deprecated. Please use tf.nn.max_pool2d instead.

W0824 12:22:43.668260 140444082550656 deprecation_wrapper.py:119] From /usr/local/lib/python3.6/dist-packages/keras/backend/tensorflow_backend.py:4025: The name tf.random_normal is deprecated. Please use tf.random.normal instead.

W0824 12:22:43.705062 140444082550656 deprecation_wrapper.py:119] From /content/gdrive/My Drive/keras-frcnn/keras_frcnn/RoiPoolingConv.py:105: The name tf.image.resize_images is deprecated. Please use tf.image.resize instead.

W0824 12:22:44.654426 140444082550656 deprecation_wrapper.py:119] From /usr/local/lib/python3.6/dist-packages/keras/backend/tensorflow_backend.py:3882: The name tf.nn.avg_pool is deprecated. Please use tf.nn.avg_pool2d instead.

loading weights from resnet50_weights_tf_dim_ordering_tf_kernels.h5
Could not load pretrained model weights. Weights can be found in the keras application folder 		https://github.com/fchollet/keras/tree/master/keras/applications
W0824 12:22:44.711113 140444082550656 deprecation_wrapper.py:119] From /usr/local/lib/python3.6/dist-packages/keras/optimizers.py:782: The name tf.train.Optimizer is deprecated. Please use tf.compat.v1.train.Optimizer instead.

W0824 12:22:44.721187 140444082550656 deprecation_wrapper.py:119] From /usr/local/lib/python3.6/dist-packages/keras/backend/tensorflow_backend.py:3299: The name tf.log is deprecated. Please use tf.math.log instead.

W0824 12:22:44.724007 140444082550656 deprecation.py:323] From /usr/local/lib/python3.6/dist-packages/tensorflow/python/ops/nn_impl.py:180: add_dispatch_support.<locals>.wrapper (from tensorflow.python.ops.array_ops) is deprecated and will be removed in a future version.
Instructions for updating:
Use tf.where in 2.0, which has the same broadcast rule as np.where
Starting training
Epoch 1/20
2019-08-24 12:22:47.659401: I tensorflow/core/platform/profile_utils/cpu_utils.cc:94] CPU Frequency: 2300000000 Hz
2019-08-24 12:22:47.659621: I tensorflow/compiler/xla/service/service.cc:168] XLA service 0x158ed80 executing computations on platform Host. Devices:
2019-08-24 12:22:47.659655: I tensorflow/compiler/xla/service/service.cc:175]   StreamExecutor device (0): <undefined>, <undefined>
2019-08-24 12:22:47.661851: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcuda.so.1
2019-08-24 12:22:47.832571: I tensorflow/stream_executor/cuda/cuda_gpu_executor.cc:1005] successful NUMA node read from SysFS had negative value (-1), but there must be at least one NUMA node, so returning NUMA node zero
2019-08-24 12:22:47.833230: I tensorflow/compiler/xla/service/service.cc:168] XLA service 0x158ef40 executing computations on platform CUDA. Devices:
2019-08-24 12:22:47.833257: I tensorflow/compiler/xla/service/service.cc:175]   StreamExecutor device (0): Tesla T4, Compute Capability 7.5
2019-08-24 12:22:47.833466: I tensorflow/stream_executor/cuda/cuda_gpu_executor.cc:1005] successful NUMA node read from SysFS had negative value (-1), but there must be at least one NUMA node, so returning NUMA node zero
2019-08-24 12:22:47.834141: I tensorflow/core/common_runtime/gpu/gpu_device.cc:1640] Found device 0 with properties:
name: Tesla T4 major: 7 minor: 5 memoryClockRate(GHz): 1.59
pciBusID: 0000:00:04.0
2019-08-24 12:22:47.834528: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcudart.so.10.0
2019-08-24 12:22:47.835847: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcublas.so.10.0
2019-08-24 12:22:47.837167: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcufft.so.10.0
2019-08-24 12:22:47.837540: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcurand.so.10.0
2019-08-24 12:22:47.839015: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcusolver.so.10.0
2019-08-24 12:22:47.840065: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcusparse.so.10.0
2019-08-24 12:22:47.843210: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcudnn.so.7
2019-08-24 12:22:47.843342: I tensorflow/stream_executor/cuda/cuda_gpu_executor.cc:1005] successful NUMA node read from SysFS had negative value (-1), but there must be at least one NUMA node, so returning NUMA node zero
2019-08-24 12:22:47.843861: I tensorflow/stream_executor/cuda/cuda_gpu_executor.cc:1005] successful NUMA node read from SysFS had negative value (-1), but there must be at least one NUMA node, so returning NUMA node zero
2019-08-24 12:22:47.844305: I tensorflow/core/common_runtime/gpu/gpu_device.cc:1763] Adding visible gpu devices: 0
2019-08-24 12:22:47.844383: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcudart.so.10.0
2019-08-24 12:22:47.845301: I tensorflow/core/common_runtime/gpu/gpu_device.cc:1181] Device interconnect StreamExecutor with strength 1 edge matrix:
2019-08-24 12:22:47.845336: I tensorflow/core/common_runtime/gpu/gpu_device.cc:1187]      0
2019-08-24 12:22:47.845347: I tensorflow/core/common_runtime/gpu/gpu_device.cc:1200] 0:   N
2019-08-24 12:22:47.845459: I tensorflow/stream_executor/cuda/cuda_gpu_executor.cc:1005] successful NUMA node read from SysFS had negative value (-1), but there must be at least one NUMA node, so returning NUMA node zero
2019-08-24 12:22:47.845968: I tensorflow/stream_executor/cuda/cuda_gpu_executor.cc:1005] successful NUMA node read from SysFS had negative value (-1), but there must be at least one NUMA node, so returning NUMA node zero
2019-08-24 12:22:47.846437: W tensorflow/core/common_runtime/gpu/gpu_bfc_allocator.cc:40] Overriding allow_growth setting because the TF_FORCE_GPU_ALLOW_GROWTH environment variable is set. Original config value was 0.
2019-08-24 12:22:47.846478: I tensorflow/core/common_runtime/gpu/gpu_device.cc:1326] Created TensorFlow device (/job:localhost/replica:0/task:0/device:GPU:0 with 14221 MB memory) -> physical GPU (device: 0, name: Tesla T4, pci bus id: 0000:00:04.0, compute capability: 7.5)
2019-08-24 12:22:52.647459: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcudnn.so.7
2019-08-24 12:23:05.860596: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcublas.so.10.0
  49/1000 [>.............................] - ETA: 20:16 - rpn_cls: 3.5055 - rpn_regr: 0.0879 - detector_cls: 0.2730 - detector_regr: 0.4536Exception: 'a' cannot be empty unless no samples are taken
 187/1000 [====>.........................] - ETA: 15:15 - rpn_cls: 2.4644 - rpn_regr: 0.0584 - detector_cls: 0.2018 - detector_regr: 0.3116Exception: 'a' cannot be empty unless no samples are taken
 335/1000 [=========>....................] - ETA: 11:32 - rpn_cls: 2.2763 - rpn_regr: 0.0545 - detector_cls: 0.2121 - detector_regr: 0.2782Exception: 'a' cannot be empty unless no samples are taken
 356/1000 [=========>....................] - ETA: 11:07 - rpn_cls: 2.2443 - rpn_regr: 0.0541 - detector_cls: 0.2132 - detector_regr: 0.2731Exception: 'a' cannot be empty unless no samples are taken
 511/1000 [==============>...............] - ETA: 8:16 - rpn_cls: 2.1570 - rpn_regr: 0.0512 - detector_cls: 0.2041 - detector_regr: 0.2529Exception: 'a' cannot be empty unless no samples are taken
 569/1000 [================>.............] - ETA: 7:14 - rpn_cls: 2.1110 - rpn_regr: 0.0509 - detector_cls: 0.2027 - detector_regr: 0.2477Exception: 'a' cannot be empty unless no samples are taken
 720/1000 [====================>.........] - ETA: 4:41 - rpn_cls: 1.9506 - rpn_regr: 0.0480 - detector_cls: 0.1938 - detector_regr: 0.2293Exception: 'a' cannot be empty unless no samples are taken
 775/1000 [======================>.......] - ETA: 3:46 - rpn_cls: 1.9185 - rpn_regr: 0.0471 - detector_cls: 0.1907 - detector_regr: 0.2262Exception: 'a' cannot be empty unless no samples are taken
 781/1000 [======================>.......] - ETA: 3:39 - rpn_cls: 1.9200 - rpn_regr: 0.0471 - detector_cls: 0.1903 - detector_regr: 0.2256Exception: 'a' cannot be empty unless no samples are taken
Exception: 'a' cannot be empty unless no samples are taken
 792/1000 [======================>.......] - ETA: 3:29 - rpn_cls: 1.9039 - rpn_regr: 0.0468 - detector_cls: 0.1894 - detector_regr: 0.2246Exception: 'a' cannot be empty unless no samples are taken
 795/1000 [======================>.......] - ETA: 3:26 - rpn_cls: 1.9076 - rpn_regr: 0.0468 - detector_cls: 0.1893 - detector_regr: 0.2244Exception: 'a' cannot be empty unless no samples are taken
 798/1000 [======================>.......] - ETA: 3:23 - rpn_cls: 1.9112 - rpn_regr: 0.0467 - detector_cls: 0.1886 - detector_regr: 0.2235Exception: 'a' cannot be empty unless no samples are taken
 800/1000 [=======================>......] - ETA: 3:21 - rpn_cls: 1.9226 - rpn_regr: 0.0467 - detector_cls: 0.1882 - detector_regr: 0.2230Exception: 'a' cannot be empty unless no samples are taken
 814/1000 [=======================>......] - ETA: 3:07 - rpn_cls: 1.9004 - rpn_regr: 0.0467 - detector_cls: 0.1877 - detector_regr: 0.2223Exception: 'a' cannot be empty unless no samples are taken
 863/1000 [========================>.....] - ETA: 2:18 - rpn_cls: 1.8844 - rpn_regr: 0.0461 - detector_cls: 0.1861 - detector_regr: 0.2206Average number of overlapping bounding boxes from RPN = 0.792 for 1000 previous iterations
 939/1000 [===========================>..] - ETA: 1:01 - rpn_cls: 1.8450 - rpn_regr: 0.0457 - detector_cls: 0.1943 - detector_regr: 0.2250Exception: 'a' cannot be empty unless no samples are taken
 946/1000 [===========================>..] - ETA: 54s - rpn_cls: 1.8314 - rpn_regr: 0.0455 - detector_cls: 0.1950 - detector_regr: 0.2254Exception: 'a' cannot be empty unless no samples are taken
 973/1000 [============================>.] - ETA: 27s - rpn_cls: 1.8205 - rpn_regr: 0.0454 - detector_cls: 0.1991 - detector_regr: 0.2275Exception: 'a' cannot be empty unless no samples are taken
1000/1000 [==============================] - 1009s 1s/step - rpn_cls: 1.7931 - rpn_regr: 0.0452 - detector_cls: 0.2015 - detector_regr: 0.2284
Mean number of bounding boxes from RPN overlapping ground truth boxes: 0.9043927648578811
Classifier accuracy for bounding boxes from RPN: 0.9669375
Loss RPN classifier: 1.793093130526313
Loss RPN regression: 0.045204644125653434
Loss Detector classifier: 0.20153442001901656
Loss Detector regression: 0.22842320014350118
Elapsed time: 1008.5690748691559
Total loss decreased from inf to 2.268255394814484, saving weights
Epoch 2/20
  65/1000 [>.............................] - ETA: 14:27 - rpn_cls: 1.0075 - rpn_regr: 0.0388 - detector_cls: 0.2542 - detector_regr: 0.2230Exception: 'a' cannot be empty unless no samples are taken
 100/1000 [==>...........................] - ETA: 14:15 - rpn_cls: 1.0540 - rpn_regr: 0.0419 - detector_cls: 0.2518 - detector_regr: 0.2388Exception: 'a' cannot be empty unless no samples are taken
 125/1000 [==>...........................] - ETA: 14:20 - rpn_cls: 1.1597 - rpn_regr: 0.0420 - detector_cls: 0.2594 - detector_regr: 0.2331Exception: 'a' cannot be empty unless no samples are taken
 188/1000 [====>.........................] - ETA: 13:23 - rpn_cls: 1.2202 - rpn_regr: 0.0392 - detector_cls: 0.2628 - detector_regr: 0.2282Exception: 'a' cannot be empty unless no samples are taken
 217/1000 [=====>........................] - ETA: 12:50 - rpn_cls: 1.2109 - rpn_regr: 0.0401 - detector_cls: 0.2621 - detector_regr: 0.2338Exception: 'a' cannot be empty unless no samples are taken
 230/1000 [=====>........................] - ETA: 13:00 - rpn_cls: 1.2680 - rpn_regr: 0.0410 - detector_cls: 0.2639 - detector_regr: 0.2372Exception: 'a' cannot be empty unless no samples are taken
 246/1000 [======>.......................] - ETA: 12:49 - rpn_cls: 1.2933 - rpn_regr: 0.0402 - detector_cls: 0.2628 - detector_regr: 0.2384Exception: 'a' cannot be empty unless no samples are taken
 281/1000 [=======>......................] - ETA: 12:10 - rpn_cls: 1.3662 - rpn_regr: 0.0393 - detector_cls: 0.2617 - detector_regr: 0.2368Exception: 'a' cannot be empty unless no samples are taken
 295/1000 [=======>......................] - ETA: 11:58 - rpn_cls: 1.3775 - rpn_regr: 0.0384 - detector_cls: 0.2591 - detector_regr: 0.2356Exception: 'a' cannot be empty unless no samples are taken
 332/1000 [========>.....................] - ETA: 11:21 - rpn_cls: 1.4076 - rpn_regr: 0.0379 - detector_cls: 0.2544 - detector_regr: 0.2319Exception: 'a' cannot be empty unless no samples are taken
 345/1000 [=========>....................] - ETA: 11:13 - rpn_cls: 1.3688 - rpn_regr: 0.0380 - detector_cls: 0.2539 - detector_regr: 0.2300Exception: 'a' cannot be empty unless no samples are taken
 372/1000 [==========>...................] - ETA: 10:45 - rpn_cls: 1.3554 - rpn_regr: 0.0381 - detector_cls: 0.2515 - detector_regr: 0.2281Exception: 'a' cannot be empty unless no samples are taken
 374/1000 [==========>...................] - ETA: 10:45 - rpn_cls: 1.3597 - rpn_regr: 0.0380 - detector_cls: 0.2519 - detector_regr: 0.2289Exception: 'a' cannot be empty unless no samples are taken
 380/1000 [==========>...................] - ETA: 10:40 - rpn_cls: 1.3496 - rpn_regr: 0.0381 - detector_cls: 0.2500 - detector_regr: 0.2274Exception: 'a' cannot be empty unless no samples are taken
 381/1000 [==========>...................] - ETA: 10:40 - rpn_cls: 1.3573 - rpn_regr: 0.0381 - detector_cls: 0.2502 - detector_regr: 0.2277Exception: 'a' cannot be empty unless no samples are taken
 411/1000 [===========>..................] - ETA: 10:10 - rpn_cls: 1.3633 - rpn_regr: 0.0378 - detector_cls: 0.2493 - detector_regr: 0.2254Exception: 'a' cannot be empty unless no samples are taken
Exception: 'a' cannot be empty unless no samples are taken
 412/1000 [===========>..................] - ETA: 10:11 - rpn_cls: 1.3600 - rpn_regr: 0.0378 - detector_cls: 0.2491 - detector_regr: 0.2255Exception: 'a' cannot be empty unless no samples are taken
 429/1000 [===========>..................] - ETA: 9:57 - rpn_cls: 1.3565 - rpn_regr: 0.0381 - detector_cls: 0.2515 - detector_regr: 0.2280Exception: 'a' cannot be empty unless no samples are taken
 462/1000 [============>.................] - ETA: 9:18 - rpn_cls: 1.3613 - rpn_regr: 0.0379 - detector_cls: 0.2558 - detector_regr: 0.2295Exception: 'a' cannot be empty unless no samples are taken
 631/1000 [=================>............] - ETA: 6:18 - rpn_cls: 1.3235 - rpn_regr: 0.0363 - detector_cls: 0.2552 - detector_regr: 0.2305Exception: 'a' cannot be empty unless no samples are taken
 651/1000 [==================>...........] - ETA: 6:00 - rpn_cls: 1.3447 - rpn_regr: 0.0368 - detector_cls: 0.2556 - detector_regr: 0.2312Exception: 'a' cannot be empty unless no samples are taken
 675/1000 [===================>..........] - ETA: 5:36 - rpn_cls: 1.3163 - rpn_regr: 0.0365 - detector_cls: 0.2550 - detector_regr: 0.2309Exception: 'a' cannot be empty unless no samples are taken
 702/1000 [====================>.........] - ETA: 5:08 - rpn_cls: 1.3131 - rpn_regr: 0.0370 - detector_cls: 0.2519 - detector_regr: 0.2286Average number of overlapping bounding boxes from RPN = 1.426 for 1000 previous iterations
 703/1000 [====================>.........] - ETA: 5:07 - rpn_cls: 1.3113 - rpn_regr: 0.0370 - detector_cls: 0.2520 - detector_regr: 0.2285Exception: 'a' cannot be empty unless no samples are taken
 757/1000 [=====================>........] - ETA: 4:08 - rpn_cls: 1.2890 - rpn_regr: 0.0366 - detector_cls: 0.2527 - detector_regr: 0.2300Exception: 'a' cannot be empty unless no samples are taken
 796/1000 [======================>.......] - ETA: 3:29 - rpn_cls: 1.2623 - rpn_regr: 0.0359 - detector_cls: 0.2518 - detector_regr: 0.2299Exception: 'a' cannot be empty unless no samples are taken
 803/1000 [=======================>......] - ETA: 3:22 - rpn_cls: 1.2643 - rpn_regr: 0.0358 - detector_cls: 0.2517 - detector_regr: 0.2305Exception: 'a' cannot be empty unless no samples are taken
 812/1000 [=======================>......] - ETA: 3:12 - rpn_cls: 1.2685 - rpn_regr: 0.0356 - detector_cls: 0.2522 - detector_regr: 0.2311Exception: 'a' cannot be empty unless no samples are taken
 818/1000 [=======================>......] - ETA: 3:06 - rpn_cls: 1.2645 - rpn_regr: 0.0356 - detector_cls: 0.2515 - detector_regr: 0.2313Exception: 'a' cannot be empty unless no samples are taken
 841/1000 [========================>.....] - ETA: 2:43 - rpn_cls: 1.2608 - rpn_regr: 0.0355 - detector_cls: 0.2511 - detector_regr: 0.2312Exception: 'a' cannot be empty unless no samples are taken
 846/1000 [========================>.....] - ETA: 2:38 - rpn_cls: 1.2553 - rpn_regr: 0.0356 - detector_cls: 0.2517 - detector_regr: 0.2316Exception: 'a' cannot be empty unless no samples are taken
 891/1000 [=========================>....] - ETA: 1:52 - rpn_cls: 1.2165 - rpn_regr: 0.0353 - detector_cls: 0.2490 - detector_regr: 0.2333Exception: 'a' cannot be empty unless no samples are taken
 911/1000 [==========================>...] - ETA: 1:31 - rpn_cls: 1.2214 - rpn_regr: 0.0352 - detector_cls: 0.2485 - detector_regr: 0.2330Exception: 'a' cannot be empty unless no samples are taken
 915/1000 [==========================>...] - ETA: 1:27 - rpn_cls: 1.2161 - rpn_regr: 0.0351 - detector_cls: 0.2487 - detector_regr: 0.2334Exception: 'a' cannot be empty unless no samples are taken
 918/1000 [==========================>...] - ETA: 1:24 - rpn_cls: 1.2168 - rpn_regr: 0.0350 - detector_cls: 0.2489 - detector_regr: 0.2334Exception: 'a' cannot be empty unless no samples are taken
 929/1000 [==========================>...] - ETA: 1:12 - rpn_cls: 1.2073 - rpn_regr: 0.0351 - detector_cls: 0.2488 - detector_regr: 0.2337Exception: 'a' cannot be empty unless no samples are taken
 930/1000 [==========================>...] - ETA: 1:11 - rpn_cls: 1.2060 - rpn_regr: 0.0351 - detector_cls: 0.2488 - detector_regr: 0.2339Exception: 'a' cannot be empty unless no samples are taken
 941/1000 [===========================>..] - ETA: 1:00 - rpn_cls: 1.2145 - rpn_regr: 0.0349 - detector_cls: 0.2491 - detector_regr: 0.2351Exception: 'a' cannot be empty unless no samples are taken
 943/1000 [===========================>..] - ETA: 58s - rpn_cls: 1.2165 - rpn_regr: 0.0349 - detector_cls: 0.2488 - detector_regr: 0.2349Exception: 'a' cannot be empty unless no samples are taken
Exception: 'a' cannot be empty unless no samples are taken
 949/1000 [===========================>..] - ETA: 52s - rpn_cls: 1.2224 - rpn_regr: 0.0348 - detector_cls: 0.2485 - detector_regr: 0.2347Exception: 'a' cannot be empty unless no samples are taken
 950/1000 [===========================>..] - ETA: 51s - rpn_cls: 1.2257 - rpn_regr: 0.0348 - detector_cls: 0.2482 - detector_regr: 0.2344Exception: 'a' cannot be empty unless no samples are taken
 980/1000 [============================>.] - ETA: 20s - rpn_cls: 1.2250 - rpn_regr: 0.0349 - detector_cls: 0.2472 - detector_regr: 0.2328Exception: 'a' cannot be empty unless no samples are taken
 989/1000 [============================>.] - ETA: 11s - rpn_cls: 1.2164 - rpn_regr: 0.0348 - detector_cls: 0.2471 - detector_regr: 0.2328Exception: 'a' cannot be empty unless no samples are taken
 994/1000 [============================>.] - ETA: 6s - rpn_cls: 1.2234 - rpn_regr: 0.0348 - detector_cls: 0.2471 - detector_regr: 0.2326Exception: 'a' cannot be empty unless no samples are taken
1000/1000 [==============================] - 1031s 1s/step - rpn_cls: 1.2204 - rpn_regr: 0.0349 - detector_cls: 0.2470 - detector_regr: 0.2330
Mean number of bounding boxes from RPN overlapping ground truth boxes: 1.415702479338843
Classifier accuracy for bounding boxes from RPN: 0.9484375
Loss RPN classifier: 1.2203725099109883
Loss RPN regression: 0.03485298622556729
Loss Detector classifier: 0.24702976536628557
Loss Detector regression: 0.23303055026568473
Elapsed time: 1049.1263272762299
Total loss decreased from 2.268255394814484 to 1.735285811768526, saving weights
Epoch 3/20
   8/1000 [..............................] - ETA: 13:25 - rpn_cls: 2.1606 - rpn_regr: 0.0147 - detector_cls: 0.2155 - detector_regr: 0.2601Exception: 'a' cannot be empty unless no samples are taken
  31/1000 [..............................] - ETA: 13:56 - rpn_cls: 1.2117 - rpn_regr: 0.0280 - detector_cls: 0.1962 - detector_regr: 0.2406Exception: 'a' cannot be empty unless no samples are taken
  36/1000 [>.............................] - ETA: 13:59 - rpn_cls: 1.0435 - rpn_regr: 0.0256 - detector_cls: 0.1961 - detector_regr: 0.2299Exception: 'a' cannot be empty unless no samples are taken
  37/1000 [>.............................] - ETA: 14:56 - rpn_cls: 1.0153 - rpn_regr: 0.0253 - detector_cls: 0.2011 - detector_regr: 0.2293Exception: 'a' cannot be empty unless no samples are taken
  39/1000 [>.............................] - ETA: 15:13 - rpn_cls: 0.9632 - rpn_regr: 0.0245 - detector_cls: 0.2145 - detector_regr: 0.2280Exception: 'a' cannot be empty unless no samples are taken
  77/1000 [=>............................] - ETA: 15:01 - rpn_cls: 1.2145 - rpn_regr: 0.0302 - detector_cls: 0.2269 - detector_regr: 0.2053Exception: 'a' cannot be empty unless no samples are taken
  80/1000 [=>............................] - ETA: 15:07 - rpn_cls: 1.1690 - rpn_regr: 0.0306 - detector_cls: 0.2187 - detector_regr: 0.1976Exception: 'a' cannot be empty unless no samples are taken
 119/1000 [==>...........................] - ETA: 14:11 - rpn_cls: 1.2200 - rpn_regr: 0.0324 - detector_cls: 0.2297 - detector_regr: 0.1989Exception: 'a' cannot be empty unless no samples are taken
 154/1000 [===>..........................] - ETA: 13:28 - rpn_cls: 1.3283 - rpn_regr: 0.0311 - detector_cls: 0.2365 - detector_regr: 0.2021Exception: 'a' cannot be empty unless no samples are taken
 169/1000 [====>.........................] - ETA: 13:13 - rpn_cls: 1.2761 - rpn_regr: 0.0305 - detector_cls: 0.2361 - detector_regr: 0.2059Exception: 'a' cannot be empty unless no samples are taken
 172/1000 [====>.........................] - ETA: 13:14 - rpn_cls: 1.2789 - rpn_regr: 0.0302 - detector_cls: 0.2367 - detector_regr: 0.2067Exception: 'a' cannot be empty unless no samples are taken
 181/1000 [====>.........................] - ETA: 13:05 - rpn_cls: 1.3105 - rpn_regr: 0.0296 - detector_cls: 0.2348 - detector_regr: 0.2046Exception: 'a' cannot be empty unless no samples are taken
 207/1000 [=====>........................] - ETA: 12:40 - rpn_cls: 1.2902 - rpn_regr: 0.0288 - detector_cls: 0.2336 - detector_regr: 0.2030Exception: 'a' cannot be empty unless no samples are taken
Exception: 'a' cannot be empty unless no samples are taken
Exception: 'a' cannot be empty unless no samples are taken
 210/1000 [=====>........................] - ETA: 12:45 - rpn_cls: 1.2718 - rpn_regr: 0.0288 - detector_cls: 0.2350 - detector_regr: 0.2036Exception: 'a' cannot be empty unless no samples are taken
 218/1000 [=====>........................] - ETA: 12:44 - rpn_cls: 1.2451 - rpn_regr: 0.0283 - detector_cls: 0.2368 - detector_regr: 0.2083Exception: 'a' cannot be empty unless no samples are taken
 227/1000 [=====>........................] - ETA: 12:36 - rpn_cls: 1.2606 - rpn_regr: 0.0280 - detector_cls: 0.2356 - detector_regr: 0.2077Exception: 'a' cannot be empty unless no samples are taken
 246/1000 [======>.......................] - ETA: 12:21 - rpn_cls: 1.2355 - rpn_regr: 0.0269 - detector_cls: 0.2350 - detector_regr: 0.2042Exception: 'a' cannot be empty unless no samples are taken
 249/1000 [======>.......................] - ETA: 12:19 - rpn_cls: 1.2206 - rpn_regr: 0.0271 - detector_cls: 0.2358 - detector_regr: 0.2048Exception: 'a' cannot be empty unless no samples are taken
 259/1000 [======>.......................] - ETA: 12:07 - rpn_cls: 1.2063 - rpn_regr: 0.0267 - detector_cls: 0.2359 - detector_regr: 0.2075Exception: 'a' cannot be empty unless no samples are taken
 260/1000 [======>.......................] - ETA: 12:08 - rpn_cls: 1.2017 - rpn_regr: 0.0267 - detector_cls: 0.2364 - detector_regr: 0.2077Exception: 'a' cannot be empty unless no samples are taken
 586/1000 [================>.............] - ETA: 6:19 - rpn_cls: 1.1349 - rpn_regr: 0.0273 - detector_cls: 0.3008 - detector_regr: 0.2404Average number of overlapping bounding boxes from RPN = 1.938 for 1000 previous iterations
1000/1000 [==============================] - 900s 900ms/step - rpn_cls: 0.9874 - rpn_regr: 0.0259 - detector_cls: 0.3290 - detector_regr: 0.2436
Mean number of bounding boxes from RPN overlapping ground truth boxes: 2.638542665388303
Classifier accuracy for bounding boxes from RPN: 0.91659375
Loss RPN classifier: 0.987423460269355
Loss RPN regression: 0.0258502284437418
Loss Detector classifier: 0.32897242103314056
Loss Detector regression: 0.24358617849461733
Elapsed time: 900.6412689685822
Total loss decreased from 1.735285811768526 to 1.5858322882408549, saving weights
Epoch 4/20
 586/1000 [================>.............] - ETA: 5:58 - rpn_cls: 0.4961 - rpn_regr: 0.0238 - detector_cls: 0.3607 - detector_regr: 0.2074Average number of overlapping bounding boxes from RPN = 3.575 for 1000 previous iterations
1000/1000 [==============================] - 801s 801ms/step - rpn_cls: 0.4083 - rpn_regr: 0.0229 - detector_cls: 0.3724 - detector_regr: 0.2032
Mean number of bounding boxes from RPN overlapping ground truth boxes: 3.959
Classifier accuracy for bounding boxes from RPN: 0.885625
Loss RPN classifier: 0.40833360264544044
Loss RPN regression: 0.02288593279570341
Loss Detector classifier: 0.3724037943445146
Loss Detector regression: 0.20317588625662028
Elapsed time: 801.6084594726562
Total loss decreased from 1.5858322882408549 to 1.0067992160422787, saving weights
Epoch 5/20
 586/1000 [================>.............] - ETA: 4:20 - rpn_cls: 0.2761 - rpn_regr: 0.0195 - detector_cls: 0.3439 - detector_regr: 0.1726Average number of overlapping bounding boxes from RPN = 4.151 for 1000 previous iterations
1000/1000 [==============================] - 631s 631ms/step - rpn_cls: 0.2640 - rpn_regr: 0.0190 - detector_cls: 0.3304 - detector_regr: 0.1701
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.157
Classifier accuracy for bounding boxes from RPN: 0.88765625
Loss RPN classifier: 0.2639948968353317
Loss RPN regression: 0.019021213190862907
Loss Detector classifier: 0.3304457963500172
Loss Detector regression: 0.1701242967909202
Elapsed time: 633.5586733818054
Total loss decreased from 1.0067992160422787 to 0.7835862031671321, saving weights
Epoch 6/20
 586/1000 [================>.............] - ETA: 4:18 - rpn_cls: 0.2010 - rpn_regr: 0.0166 - detector_cls: 0.2872 - detector_regr: 0.1603Average number of overlapping bounding boxes from RPN = 4.172 for 1000 previous iterations
1000/1000 [==============================] - 625s 625ms/step - rpn_cls: 0.1746 - rpn_regr: 0.0173 - detector_cls: 0.2754 - detector_regr: 0.1584
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.118
Classifier accuracy for bounding boxes from RPN: 0.90353125
Loss RPN classifier: 0.1746225601857351
Loss RPN regression: 0.017271599373911158
Loss Detector classifier: 0.27540222597308456
Loss Detector regression: 0.1584252337180078
Elapsed time: 628.4695551395416
Total loss decreased from 0.7835862031671321 to 0.6257216192507385, saving weights
Epoch 7/20
 586/1000 [================>.............] - ETA: 4:16 - rpn_cls: 0.2461 - rpn_regr: 0.0172 - detector_cls: 0.2816 - detector_regr: 0.1519Average number of overlapping bounding boxes from RPN = 4.225 for 1000 previous iterations
1000/1000 [==============================] - 614s 614ms/step - rpn_cls: 0.2530 - rpn_regr: 0.0169 - detector_cls: 0.2745 - detector_regr: 0.1510
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.372
Classifier accuracy for bounding boxes from RPN: 0.9018125
Loss RPN classifier: 0.2530428050743898
Loss RPN regression: 0.01690889258115203
Loss Detector classifier: 0.2744718361645937
Loss Detector regression: 0.15103907065535896
Elapsed time: 616.8997566699982
Epoch 8/20
 586/1000 [================>.............] - ETA: 4:17 - rpn_cls: 0.2715 - rpn_regr: 0.0156 - detector_cls: 0.2459 - detector_regr: 0.1411Average number of overlapping bounding boxes from RPN = 4.348 for 1000 previous iterations
1000/1000 [==============================] - 622s 622ms/step - rpn_cls: 0.2611 - rpn_regr: 0.0155 - detector_cls: 0.2500 - detector_regr: 0.1392
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.312
Classifier accuracy for bounding boxes from RPN: 0.90740625
Loss RPN classifier: 0.26114047254460543
Loss RPN regression: 0.01549729292903794
Loss Detector classifier: 0.2500262384021189
Loss Detector regression: 0.13922099308110775
Elapsed time: 621.6459724903107
Epoch 9/20
 586/1000 [================>.............] - ETA: 4:14 - rpn_cls: 0.1359 - rpn_regr: 0.0147 - detector_cls: 0.2154 - detector_regr: 0.1315Average number of overlapping bounding boxes from RPN = 4.349 for 1000 previous iterations
1000/1000 [==============================] - 611s 611ms/step - rpn_cls: 0.1125 - rpn_regr: 0.0144 - detector_cls: 0.2150 - detector_regr: 0.1300
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.377
Classifier accuracy for bounding boxes from RPN: 0.9196875
Loss RPN classifier: 0.11245538655710195
Loss RPN regression: 0.014409614677941135
Loss Detector classifier: 0.21496783972904085
Loss Detector regression: 0.12998452924191953
Elapsed time: 610.5619027614594
Total loss decreased from 0.6257216192507385 to 0.47181737020600345, saving weights
Epoch 10/20
 586/1000 [================>.............] - ETA: 4:07 - rpn_cls: 0.0975 - rpn_regr: 0.0135 - detector_cls: 0.2220 - detector_regr: 0.1225Average number of overlapping bounding boxes from RPN = 4.47 for 1000 previous iterations
1000/1000 [==============================] - 600s 600ms/step - rpn_cls: 0.1335 - rpn_regr: 0.0145 - detector_cls: 0.2113 - detector_regr: 0.1266
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.42
Classifier accuracy for bounding boxes from RPN: 0.91959375
Loss RPN classifier: 0.1335480882180132
Loss RPN regression: 0.014507837068638764
Loss Detector classifier: 0.21131665221601725
Loss Detector regression: 0.12662569164205342
Elapsed time: 602.9827454090118
Epoch 11/20
 222/1000 [=====>........................] - ETA: 7:55 - rpn_cls: 0.1449 - rpn_regr: 0.0154 - detector_cls: 0.2053 - detector_regr: 0.1331Exception: 'a' cannot be empty unless no samples are taken
 585/1000 [================>.............] - ETA: 4:13 - rpn_cls: 0.1552 - rpn_regr: 0.0148 - detector_cls: 0.2085 - detector_regr: 0.1278Average number of overlapping bounding boxes from RPN = 4.382 for 1000 previous iterations
1000/1000 [==============================] - 612s 612ms/step - rpn_cls: 0.1469 - rpn_regr: 0.0145 - detector_cls: 0.2110 - detector_regr: 0.1255
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.393606393606394
Classifier accuracy for bounding boxes from RPN: 0.92034375
Loss RPN classifier: 0.14688284202181243
Loss RPN regression: 0.014480260546602949
Loss Detector classifier: 0.2110161257344298
Loss Detector regression: 0.1254787494475022
Elapsed time: 611.977249622345
Epoch 12/20
 585/1000 [================>.............] - ETA: 4:05 - rpn_cls: 0.1053 - rpn_regr: 0.0144 - detector_cls: 0.2075 - detector_regr: 0.1149Average number of overlapping bounding boxes from RPN = 4.546 for 1000 previous iterations
1000/1000 [==============================] - 590s 590ms/step - rpn_cls: 0.1029 - rpn_regr: 0.0135 - detector_cls: 0.1979 - detector_regr: 0.1160
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.635
Classifier accuracy for bounding boxes from RPN: 0.9230625
Loss RPN classifier: 0.10294016029988291
Loss RPN regression: 0.013480092621903169
Loss Detector classifier: 0.19791831413656474
Loss Detector regression: 0.11601966864615679
Elapsed time: 589.8606197834015
Total loss decreased from 0.47181737020600345 to 0.4303582357045076, saving weights
Epoch 13/20
 585/1000 [================>.............] - ETA: 4:08 - rpn_cls: 0.1280 - rpn_regr: 0.0131 - detector_cls: 0.1994 - detector_regr: 0.1116Average number of overlapping bounding boxes from RPN = 4.678 for 1000 previous iterations
1000/1000 [==============================] - 593s 593ms/step - rpn_cls: 0.1140 - rpn_regr: 0.0125 - detector_cls: 0.1991 - detector_regr: 0.1137
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.723
Classifier accuracy for bounding boxes from RPN: 0.92296875
Loss RPN classifier: 0.11397632564366553
Loss RPN regression: 0.012480011408631982
Loss Detector classifier: 0.1991373142749071
Loss Detector regression: 0.11369256011699326
Elapsed time: 594.7245876789093
Epoch 14/20
 585/1000 [================>.............] - ETA: 4:03 - rpn_cls: 0.1039 - rpn_regr: 0.0131 - detector_cls: 0.1987 - detector_regr: 0.1174Average number of overlapping bounding boxes from RPN = 4.715 for 1000 previous iterations
1000/1000 [==============================] - 586s 586ms/step - rpn_cls: 0.0971 - rpn_regr: 0.0129 - detector_cls: 0.2009 - detector_regr: 0.1144
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.873
Classifier accuracy for bounding boxes from RPN: 0.92096875
Loss RPN classifier: 0.09705108048337435
Loss RPN regression: 0.012874384224138339
Loss Detector classifier: 0.20088549561426045
Loss Detector regression: 0.11440689532272517
Elapsed time: 586.0709140300751
Total loss decreased from 0.4303582357045076 to 0.4252178556444983, saving weights
Epoch 15/20
 585/1000 [================>.............] - ETA: 4:03 - rpn_cls: 0.0833 - rpn_regr: 0.0111 - detector_cls: 0.1965 - detector_regr: 0.1045Average number of overlapping bounding boxes from RPN = 4.92 for 1000 previous iterations
1000/1000 [==============================] - 584s 584ms/step - rpn_cls: 0.0853 - rpn_regr: 0.0117 - detector_cls: 0.1958 - detector_regr: 0.1066
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.929
Classifier accuracy for bounding boxes from RPN: 0.92359375
Loss RPN classifier: 0.08532472550693691
Loss RPN regression: 0.011724889266610262
Loss Detector classifier: 0.19580748910270632
Loss Detector regression: 0.1065859799911268
Elapsed time: 585.6148743629456
Total loss decreased from 0.4252178556444983 to 0.3994430838673803, saving weights
Epoch 16/20
 585/1000 [================>.............] - ETA: 4:03 - rpn_cls: 0.1174 - rpn_regr: 0.0128 - detector_cls: 0.1956 - detector_regr: 0.1093Average number of overlapping bounding boxes from RPN = 4.916 for 1000 previous iterations
1000/1000 [==============================] - 587s 587ms/step - rpn_cls: 0.1107 - rpn_regr: 0.0128 - detector_cls: 0.1967 - detector_regr: 0.1089
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.833
Classifier accuracy for bounding boxes from RPN: 0.92009375
Loss RPN classifier: 0.11067892105574506
Loss RPN regression: 0.012752118925185641
Loss Detector classifier: 0.19669937757588923
Loss Detector regression: 0.10887276936415582
Elapsed time: 589.8693852424622
Epoch 17/20
 585/1000 [================>.............] - ETA: 4:01 - rpn_cls: 0.0835 - rpn_regr: 0.0126 - detector_cls: 0.1790 - detector_regr: 0.1067Average number of overlapping bounding boxes from RPN = 4.912 for 1000 previous iterations
1000/1000 [==============================] - 579s 579ms/step - rpn_cls: 0.0744 - rpn_regr: 0.0118 - detector_cls: 0.1712 - detector_regr: 0.1025
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.969
Classifier accuracy for bounding boxes from RPN: 0.9308125
Loss RPN classifier: 0.07444803535618667
Loss RPN regression: 0.01184765187823359
Loss Detector classifier: 0.17124125589057804
Loss Detector regression: 0.10249401257839054
Elapsed time: 579.4033370018005
Total loss decreased from 0.3994430838673803 to 0.36003095570338883, saving weights
Epoch 18/20
 585/1000 [================>.............] - ETA: 4:01 - rpn_cls: 0.1162 - rpn_regr: 0.0130 - detector_cls: 0.1898 - detector_regr: 0.1026Average number of overlapping bounding boxes from RPN = 4.89 for 1000 previous iterations
1000/1000 [==============================] - 586s 586ms/step - rpn_cls: 0.0957 - rpn_regr: 0.0126 - detector_cls: 0.1956 - detector_regr: 0.1018
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.838
Classifier accuracy for bounding boxes from RPN: 0.92040625
Loss RPN classifier: 0.09571381431363722
Loss RPN regression: 0.012596260093501769
Loss Detector classifier: 0.19559695104230196
Loss Detector regression: 0.10176602678187191
Elapsed time: 588.5452220439911
Epoch 19/20
 585/1000 [================>.............] - ETA: 4:03 - rpn_cls: 0.1364 - rpn_regr: 0.0115 - detector_cls: 0.1755 - detector_regr: 0.1054Average number of overlapping bounding boxes from RPN = 4.719 for 1000 previous iterations
1000/1000 [==============================] - 581s 581ms/step - rpn_cls: 0.1053 - rpn_regr: 0.0115 - detector_cls: 0.1710 - detector_regr: 0.1021
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.624
Classifier accuracy for bounding boxes from RPN: 0.9289375
Loss RPN classifier: 0.10529214617982635
Loss RPN regression: 0.01149253297453106
Loss Detector classifier: 0.17096690825372934
Loss Detector regression: 0.10206601111078635
Elapsed time: 580.8243637084961
Epoch 20/20
 585/1000 [================>.............] - ETA: 4:00 - rpn_cls: 0.0707 - rpn_regr: 0.0115 - detector_cls: 0.1666 - detector_regr: 0.1011Average number of overlapping bounding boxes from RPN = 4.692 for 1000 previous iterations
1000/1000 [==============================] - 579s 579ms/step - rpn_cls: 0.0694 - rpn_regr: 0.0111 - detector_cls: 0.1661 - detector_regr: 0.1021
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.712
Classifier accuracy for bounding boxes from RPN: 0.931375
Loss RPN classifier: 0.06943424686098028
Loss RPN regression: 0.011125958581666054
Loss Detector classifier: 0.16614455935452133
Loss Detector regression: 0.10208193124644459
Elapsed time: 579.2788133621216
Total loss decreased from 0.36003095570338883 to 0.34878669604361223, saving weights
Training complete, exiting.

# 2차시도 -> 실패
# 원인은 colab내 경로 문제
# 코드의 default 경로를 변경하고 colab내 유효한 경로에 저장할 것
Using TensorFlow backend.
Parsing annotation files
Training images per class:
{'bg': 0,
 'shape_a': 560,
 'shape_e': 532,
 'shape_eu': 552,
 'shape_i': 518,
 'shape_none': 600,
 'shape_o': 590,
 'shape_u': 600,
 'shape_ui': 598}
Num classes (including bg) = 9
Config has been written to config.pickle, and can be loaded when testing to ensure correct results
Num train samples 4120
Num val samples 430
WARNING: Logging before flag parsing goes to stderr.
W0824 04:40:18.562801 140356480673664 deprecation_wrapper.py:119] From /usr/local/lib/python3.6/dist-packages/keras/backend/tensorflow_backend.py:72: The name tf.get_default_graph is deprecated. Please use tf.compat.v1.get_default_graph instead.

W0824 04:40:18.607109 140356480673664 deprecation_wrapper.py:119] From /usr/local/lib/python3.6/dist-packages/keras/backend/tensorflow_backend.py:515: The name tf.placeholder is deprecated. Please use tf.compat.v1.placeholder instead.

W0824 04:40:18.617862 140356480673664 deprecation_wrapper.py:119] From /usr/local/lib/python3.6/dist-packages/keras/backend/tensorflow_backend.py:4048: The name tf.random_uniform is deprecated. Please use tf.random.uniform instead.

W0824 04:40:18.654690 140356480673664 deprecation_wrapper.py:119] From /usr/local/lib/python3.6/dist-packages/keras/backend/tensorflow_backend.py:1897: The name tf.nn.fused_batch_norm is deprecated. Please use tf.compat.v1.nn.fused_batch_norm instead.

W0824 04:40:18.656278 140356480673664 deprecation_wrapper.py:119] From /usr/local/lib/python3.6/dist-packages/keras/backend/tensorflow_backend.py:3878: The name tf.nn.max_pool is deprecated. Please use tf.nn.max_pool2d instead.

W0824 04:40:19.774029 140356480673664 deprecation_wrapper.py:119] From /usr/local/lib/python3.6/dist-packages/keras/backend/tensorflow_backend.py:4025: The name tf.random_normal is deprecated. Please use tf.random.normal instead.

W0824 04:40:19.809734 140356480673664 deprecation_wrapper.py:119] From /content/gdrive/My Drive/keras-frcnn/keras_frcnn/RoiPoolingConv.py:105: The name tf.image.resize_images is deprecated. Please use tf.image.resize instead.

W0824 04:40:20.733584 140356480673664 deprecation_wrapper.py:119] From /usr/local/lib/python3.6/dist-packages/keras/backend/tensorflow_backend.py:3882: The name tf.nn.avg_pool is deprecated. Please use tf.nn.avg_pool2d instead.

loading weights from resnet50_weights_tf_dim_ordering_tf_kernels.h5
Could not load pretrained model weights. Weights can be found in the keras application folder 		https://github.com/fchollet/keras/tree/master/keras/applications
W0824 04:40:20.838008 140356480673664 deprecation_wrapper.py:119] From /usr/local/lib/python3.6/dist-packages/keras/optimizers.py:782: The name tf.train.Optimizer is deprecated. Please use tf.compat.v1.train.Optimizer instead.

W0824 04:40:20.848027 140356480673664 deprecation_wrapper.py:119] From /usr/local/lib/python3.6/dist-packages/keras/backend/tensorflow_backend.py:3299: The name tf.log is deprecated. Please use tf.math.log instead.

W0824 04:40:20.850798 140356480673664 deprecation.py:323] From /usr/local/lib/python3.6/dist-packages/tensorflow/python/ops/nn_impl.py:180: add_dispatch_support.<locals>.wrapper (from tensorflow.python.ops.array_ops) is deprecated and will be removed in a future version.
Instructions for updating:
Use tf.where in 2.0, which has the same broadcast rule as np.where
Starting training
Epoch 1/16
2019-08-24 04:40:23.722806: I tensorflow/core/platform/profile_utils/cpu_utils.cc:94] CPU Frequency: 2300000000 Hz
2019-08-24 04:40:23.724613: I tensorflow/compiler/xla/service/service.cc:168] XLA service 0x1714d80 executing computations on platform Host. Devices:
2019-08-24 04:40:23.724658: I tensorflow/compiler/xla/service/service.cc:175]   StreamExecutor device (0): <undefined>, <undefined>
2019-08-24 04:40:23.730937: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcuda.so.1
2019-08-24 04:40:23.945528: I tensorflow/stream_executor/cuda/cuda_gpu_executor.cc:1005] successful NUMA node read from SysFS had negative value (-1), but there must be at least one NUMA node, so returning NUMA node zero
2019-08-24 04:40:23.946248: I tensorflow/compiler/xla/service/service.cc:168] XLA service 0x1714f40 executing computations on platform CUDA. Devices:
2019-08-24 04:40:23.946277: I tensorflow/compiler/xla/service/service.cc:175]   StreamExecutor device (0): Tesla T4, Compute Capability 7.5
2019-08-24 04:40:23.947787: I tensorflow/stream_executor/cuda/cuda_gpu_executor.cc:1005] successful NUMA node read from SysFS had negative value (-1), but there must be at least one NUMA node, so returning NUMA node zero
2019-08-24 04:40:23.948357: I tensorflow/core/common_runtime/gpu/gpu_device.cc:1640] Found device 0 with properties:
name: Tesla T4 major: 7 minor: 5 memoryClockRate(GHz): 1.59
pciBusID: 0000:00:04.0
2019-08-24 04:40:23.979641: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcudart.so.10.0
2019-08-24 04:40:24.178661: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcublas.so.10.0
2019-08-24 04:40:24.270695: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcufft.so.10.0
2019-08-24 04:40:24.297086: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcurand.so.10.0
2019-08-24 04:40:24.501274: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcusolver.so.10.0
2019-08-24 04:40:24.620718: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcusparse.so.10.0
2019-08-24 04:40:25.034172: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcudnn.so.7
2019-08-24 04:40:25.034392: I tensorflow/stream_executor/cuda/cuda_gpu_executor.cc:1005] successful NUMA node read from SysFS had negative value (-1), but there must be at least one NUMA node, so returning NUMA node zero
2019-08-24 04:40:25.035112: I tensorflow/stream_executor/cuda/cuda_gpu_executor.cc:1005] successful NUMA node read from SysFS had negative value (-1), but there must be at least one NUMA node, so returning NUMA node zero
2019-08-24 04:40:25.035603: I tensorflow/core/common_runtime/gpu/gpu_device.cc:1763] Adding visible gpu devices: 0
2019-08-24 04:40:25.039580: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcudart.so.10.0
2019-08-24 04:40:25.040756: I tensorflow/core/common_runtime/gpu/gpu_device.cc:1181] Device interconnect StreamExecutor with strength 1 edge matrix:
2019-08-24 04:40:25.040785: I tensorflow/core/common_runtime/gpu/gpu_device.cc:1187]      0
2019-08-24 04:40:25.040795: I tensorflow/core/common_runtime/gpu/gpu_device.cc:1200] 0:   N
2019-08-24 04:40:25.042802: I tensorflow/stream_executor/cuda/cuda_gpu_executor.cc:1005] successful NUMA node read from SysFS had negative value (-1), but there must be at least one NUMA node, so returning NUMA node zero
2019-08-24 04:40:25.043414: I tensorflow/stream_executor/cuda/cuda_gpu_executor.cc:1005] successful NUMA node read from SysFS had negative value (-1), but there must be at least one NUMA node, so returning NUMA node zero
2019-08-24 04:40:25.043946: W tensorflow/core/common_runtime/gpu/gpu_bfc_allocator.cc:40] Overriding allow_growth setting because the TF_FORCE_GPU_ALLOW_GROWTH environment variable is set. Original config value was 0.
2019-08-24 04:40:25.043988: I tensorflow/core/common_runtime/gpu/gpu_device.cc:1326] Created TensorFlow device (/job:localhost/replica:0/task:0/device:GPU:0 with 14221 MB memory) -> physical GPU (device: 0, name: Tesla T4, pci bus id: 0000:00:04.0, compute capability: 7.5)
2019-08-24 04:40:31.169400: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcudnn.so.7
2019-08-24 04:40:45.556115: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcublas.so.10.0
 112/1000 [==>...........................] - ETA: 20:23 - rpn_cls: 2.0818 - rpn_regr: 0.0778 - detector_cls: 0.3018 - detector_regr: 0.3027Exception: 'a' cannot be empty unless no samples are taken
 113/1000 [==>...........................] - ETA: 20:47 - rpn_cls: 2.1048 - rpn_regr: 0.0774 - detector_cls: 0.3011 - detector_regr: 0.3022Exception: 'a' cannot be empty unless no samples are taken
 114/1000 [==>...........................] - ETA: 20:50 - rpn_cls: 2.1244 - rpn_regr: 0.0768 - detector_cls: 0.3000 - detector_regr: 0.2997Exception: 'a' cannot be empty unless no samples are taken
 116/1000 [==>...........................] - ETA: 20:44 - rpn_cls: 2.1248 - rpn_regr: 0.0766 - detector_cls: 0.2997 - detector_regr: 0.3001Exception: 'a' cannot be empty unless no samples are taken
 225/1000 [=====>........................] - ETA: 16:37 - rpn_cls: 1.8755 - rpn_regr: 0.0554 - detector_cls: 0.2518 - detector_regr: 0.2540Exception: 'a' cannot be empty unless no samples are taken
 260/1000 [======>.......................] - ETA: 15:45 - rpn_cls: 1.8613 - rpn_regr: 0.0557 - detector_cls: 0.2410 - detector_regr: 0.2473Exception: 'a' cannot be empty unless no samples are taken
 302/1000 [========>.....................] - ETA: 14:42 - rpn_cls: 1.7643 - rpn_regr: 0.0542 - detector_cls: 0.2357 - detector_regr: 0.2449Exception: 'a' cannot be empty unless no samples are taken
 339/1000 [=========>....................] - ETA: 13:39 - rpn_cls: 1.7555 - rpn_regr: 0.0527 - detector_cls: 0.2290 - detector_regr: 0.2433Exception: 'a' cannot be empty unless no samples are taken
 413/1000 [===========>..................] - ETA: 12:01 - rpn_cls: 1.6841 - rpn_regr: 0.0502 - detector_cls: 0.2282 - detector_regr: 0.2394Exception: 'a' cannot be empty unless no samples are taken
 570/1000 [================>.............] - ETA: 8:35 - rpn_cls: 1.5529 - rpn_regr: 0.0472 - detector_cls: 0.2245 - detector_regr: 0.2356Exception: 'a' cannot be empty unless no samples are taken
 764/1000 [=====================>........] - ETA: 4:38 - rpn_cls: 1.4229 - rpn_regr: 0.0455 - detector_cls: 0.2270 - detector_regr: 0.2316Exception: 'a' cannot be empty unless no samples are taken
 794/1000 [======================>.......] - ETA: 4:02 - rpn_cls: 1.4029 - rpn_regr: 0.0451 - detector_cls: 0.2276 - detector_regr: 0.2315Exception: 'a' cannot be empty unless no samples are taken
 870/1000 [=========================>....] - ETA: 2:31 - rpn_cls: 1.3704 - rpn_regr: 0.0457 - detector_cls: 0.2302 - detector_regr: 0.2322Average number of overlapping bounding boxes from RPN = 1.084 for 1000 previous iterations
1000/1000 [==============================] - 1143s 1s/step - rpn_cls: 1.3552 - rpn_regr: 0.0446 - detector_cls: 0.2341 - detector_regr: 0.2345
Mean number of bounding boxes from RPN overlapping ground truth boxes: 1.148278905560459
Classifier accuracy for bounding boxes from RPN: 0.9588125
Loss RPN classifier: 1.3552170849771956
Loss RPN regression: 0.04458879431028617
Loss Detector classifier: 0.23409492871227128
Loss Detector regression: 0.2344535001758486
Elapsed time: 1142.6632854938507
Total loss decreased from inf to 1.8683543081756016, saving weights
Epoch 2/16
  25/1000 [..............................] - ETA: 18:13 - rpn_cls: 1.2518 - rpn_regr: 0.0265 - detector_cls: 0.2104 - detector_regr: 0.2044Exception: 'a' cannot be empty unless no samples are taken
  32/1000 [..............................] - ETA: 17:53 - rpn_cls: 1.1193 - rpn_regr: 0.0291 - detector_cls: 0.2337 - detector_regr: 0.2273Exception: 'a' cannot be empty unless no samples are taken
  48/1000 [>.............................] - ETA: 17:36 - rpn_cls: 1.0270 - rpn_regr: 0.0289 - detector_cls: 0.2457 - detector_regr: 0.2613Exception: 'a' cannot be empty unless no samples are taken
 162/1000 [===>..........................] - ETA: 15:45 - rpn_cls: 0.9031 - rpn_regr: 0.0331 - detector_cls: 0.2516 - detector_regr: 0.2591Exception: 'a' cannot be empty unless no samples are taken
 168/1000 [====>.........................] - ETA: 15:44 - rpn_cls: 0.9275 - rpn_regr: 0.0334 - detector_cls: 0.2518 - detector_regr: 0.2555Exception: 'a' cannot be empty unless no samples are taken
 197/1000 [====>.........................] - ETA: 15:17 - rpn_cls: 0.9759 - rpn_regr: 0.0319 - detector_cls: 0.2499 - detector_regr: 0.2590Exception: 'a' cannot be empty unless no samples are taken
 201/1000 [=====>........................] - ETA: 15:16 - rpn_cls: 0.9992 - rpn_regr: 0.0316 - detector_cls: 0.2483 - detector_regr: 0.2579Exception: 'a' cannot be empty unless no samples are taken
 202/1000 [=====>........................] - ETA: 15:18 - rpn_cls: 1.0155 - rpn_regr: 0.0315 - detector_cls: 0.2492 - detector_regr: 0.2583Exception: 'a' cannot be empty unless no samples are taken
 475/1000 [=============>................] - ETA: 9:38 - rpn_cls: 0.9286 - rpn_regr: 0.0337 - detector_cls: 0.2607 - detector_regr: 0.2580Exception: 'a' cannot be empty unless no samples are taken
 505/1000 [==============>...............] - ETA: 9:05 - rpn_cls: 0.9353 - rpn_regr: 0.0335 - detector_cls: 0.2611 - detector_regr: 0.2560Exception: 'a' cannot be empty unless no samples are taken
 559/1000 [===============>..............] - ETA: 8:03 - rpn_cls: 0.9351 - rpn_regr: 0.0340 - detector_cls: 0.2701 - detector_regr: 0.2577Exception: 'a' cannot be empty unless no samples are taken
 561/1000 [===============>..............] - ETA: 8:02 - rpn_cls: 0.9395 - rpn_regr: 0.0340 - detector_cls: 0.2703 - detector_regr: 0.2577Exception: 'a' cannot be empty unless no samples are taken
 804/1000 [=======================>......] - ETA: 3:31 - rpn_cls: 0.8831 - rpn_regr: 0.0330 - detector_cls: 0.2776 - detector_regr: 0.2534Average number of overlapping bounding boxes from RPN = 1.946 for 1000 previous iterations
1000/1000 [==============================] - 1062s 1s/step - rpn_cls: 0.8059 - rpn_regr: 0.0317 - detector_cls: 0.3016 - detector_regr: 0.2514
Mean number of bounding boxes from RPN overlapping ground truth boxes: 2.282220131702728
Classifier accuracy for bounding boxes from RPN: 0.926125
Loss RPN classifier: 0.8059080627010662
Loss RPN regression: 0.03166492810705677
Loss Detector classifier: 0.3016147011955036
Loss Detector regression: 0.25135884821321813
Elapsed time: 1077.5104613304138
Total loss decreased from 1.8683543081756016 to 1.3905465402168447, saving weights
Epoch 3/16
 804/1000 [=======================>......] - ETA: 3:11 - rpn_cls: 0.3867 - rpn_regr: 0.0255 - detector_cls: 0.3941 - detector_regr: 0.2103Average number of overlapping bounding boxes from RPN = 3.87 for 1000 previous iterations
1000/1000 [==============================] - 977s 977ms/step - rpn_cls: 0.3605 - rpn_regr: 0.0244 - detector_cls: 0.3885 - detector_regr: 0.2053
Mean number of bounding boxes from RPN overlapping ground truth boxes: 3.981
Classifier accuracy for bounding boxes from RPN: 0.882
Loss RPN classifier: 0.3605044433350968
Loss RPN regression: 0.024431880107702454
Loss Detector classifier: 0.3885263167582452
Loss Detector regression: 0.20533193069696426
Elapsed time: 977.0765087604523
Total loss decreased from 1.3905465402168447 to 0.9787945708980088, saving weights
Epoch 4/16
 804/1000 [=======================>......] - ETA: 3:14 - rpn_cls: 0.2914 - rpn_regr: 0.0204 - detector_cls: 0.3127 - detector_regr: 0.1732Average number of overlapping bounding boxes from RPN = 3.941 for 1000 previous iterations
1000/1000 [==============================] - 956s 956ms/step - rpn_cls: 0.2759 - rpn_regr: 0.0196 - detector_cls: 0.3094 - detector_regr: 0.1687
Mean number of bounding boxes from RPN overlapping ground truth boxes: 3.874
Classifier accuracy for bounding boxes from RPN: 0.89865625
Loss RPN classifier: 0.27587303062656626
Loss RPN regression: 0.01962224442846491
Loss Detector classifier: 0.30940970507264137
Loss Detector regression: 0.16873012784309685
Elapsed time: 956.8224477767944
Total loss decreased from 0.9787945708980088 to 0.7736351079707693, saving weights
Epoch 5/16
 804/1000 [=======================>......] - ETA: 2:01 - rpn_cls: 0.2219 - rpn_regr: 0.0202 - detector_cls: 0.2773 - detector_regr: 0.1573Average number of overlapping bounding boxes from RPN = 3.96 for 1000 previous iterations
1000/1000 [==============================] - 618s 618ms/step - rpn_cls: 0.2294 - rpn_regr: 0.0194 - detector_cls: 0.2790 - detector_regr: 0.1553
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.104
Classifier accuracy for bounding boxes from RPN: 0.9021875
Loss RPN classifier: 0.2294221313579055
Loss RPN regression: 0.01944688424025662
Loss Detector classifier: 0.2789931109901518
Loss Detector regression: 0.15534522204520182
Elapsed time: 618.6245322227478
Total loss decreased from 0.7736351079707693 to 0.6832073486335157, saving weights
Epoch 6/16
 804/1000 [=======================>......] - ETA: 2:00 - rpn_cls: 0.1741 - rpn_regr: 0.0159 - detector_cls: 0.2582 - detector_regr: 0.1404Average number of overlapping bounding boxes from RPN = 4.358 for 1000 previous iterations
1000/1000 [==============================] - 615s 615ms/step - rpn_cls: 0.2038 - rpn_regr: 0.0162 - detector_cls: 0.2590 - detector_regr: 0.1414
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.303
Classifier accuracy for bounding boxes from RPN: 0.90540625
Loss RPN classifier: 0.2037867099188215
Loss RPN regression: 0.016230015034176176
Loss Detector classifier: 0.2589801383749582
Loss Detector regression: 0.14135606529656797
Elapsed time: 614.9346606731415
Total loss decreased from 0.6832073486335157 to 0.6203529286245238, saving weights
Epoch 7/16
 804/1000 [=======================>......] - ETA: 1:59 - rpn_cls: 0.1998 - rpn_regr: 0.0158 - detector_cls: 0.2439 - detector_regr: 0.1365Average number of overlapping bounding boxes from RPN = 4.196 for 1000 previous iterations
1000/1000 [==============================] - 608s 608ms/step - rpn_cls: 0.2011 - rpn_regr: 0.0159 - detector_cls: 0.2408 - detector_regr: 0.1351
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.165
Classifier accuracy for bounding boxes from RPN: 0.9110625
Loss RPN classifier: 0.20111006538865808
Loss RPN regression: 0.015888687614977245
Loss Detector classifier: 0.24075307317823172
Loss Detector regression: 0.13509652782231568
Elapsed time: 608.6187047958374
Total loss decreased from 0.6203529286245238 to 0.5928483540041827, saving weights
Epoch 8/16
 804/1000 [=======================>......] - ETA: 1:58 - rpn_cls: 0.1607 - rpn_regr: 0.0144 - detector_cls: 0.2418 - detector_regr: 0.1314Average number of overlapping bounding boxes from RPN = 4.466 for 1000 previous iterations
1000/1000 [==============================] - 603s 603ms/step - rpn_cls: 0.1699 - rpn_regr: 0.0143 - detector_cls: 0.2418 - detector_regr: 0.1288
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.556
Classifier accuracy for bounding boxes from RPN: 0.91134375
Loss RPN classifier: 0.1698922504664216
Loss RPN regression: 0.014290151316368791
Loss Detector classifier: 0.24178294937685132
Loss Detector regression: 0.12876562184933574
Elapsed time: 603.0305585861206
Total loss decreased from 0.5928483540041827 to 0.5547309730089774, saving weights
Epoch 9/16
 804/1000 [=======================>......] - ETA: 1:56 - rpn_cls: 0.1656 - rpn_regr: 0.0158 - detector_cls: 0.2066 - detector_regr: 0.1239Average number of overlapping bounding boxes from RPN = 4.424 for 1000 previous iterations
1000/1000 [==============================] - 596s 596ms/step - rpn_cls: 0.1524 - rpn_regr: 0.0156 - detector_cls: 0.2097 - detector_regr: 0.1238
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.383
Classifier accuracy for bounding boxes from RPN: 0.91821875
Loss RPN classifier: 0.15242721320584207
Loss RPN regression: 0.015620006227109115
Loss Detector classifier: 0.20970940400939433
Loss Detector regression: 0.12382787449005991
Elapsed time: 596.669525384903
Total loss decreased from 0.5547309730089774 to 0.5015844979324054, saving weights
Epoch 10/16
 804/1000 [=======================>......] - ETA: 1:55 - rpn_cls: 0.1301 - rpn_regr: 0.0131 - detector_cls: 0.1935 - detector_regr: 0.1172Average number of overlapping bounding boxes from RPN = 4.268 for 1000 previous iterations
1000/1000 [==============================] - 588s 588ms/step - rpn_cls: 0.1525 - rpn_regr: 0.0129 - detector_cls: 0.1958 - detector_regr: 0.1154
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.302
Classifier accuracy for bounding boxes from RPN: 0.92315625
Loss RPN classifier: 0.152468430673211
Loss RPN regression: 0.01293429344521428
Loss Detector classifier: 0.19579908264055848
Loss Detector regression: 0.11543244623625651
Elapsed time: 588.4137859344482
Total loss decreased from 0.5015844979324054 to 0.4766342529952402, saving weights
Epoch 11/16
 804/1000 [=======================>......] - ETA: 1:54 - rpn_cls: 0.0907 - rpn_regr: 0.0129 - detector_cls: 0.1959 - detector_regr: 0.1151Average number of overlapping bounding boxes from RPN = 4.447 for 1000 previous iterations
1000/1000 [==============================] - 587s 587ms/step - rpn_cls: 0.0842 - rpn_regr: 0.0129 - detector_cls: 0.1987 - detector_regr: 0.1156
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.467
Classifier accuracy for bounding boxes from RPN: 0.923375
Loss RPN classifier: 0.08418407084089696
Loss RPN regression: 0.012864313703103107
Loss Detector classifier: 0.19866360364761204
Loss Detector regression: 0.11557372653950006
Elapsed time: 587.8389856815338
Total loss decreased from 0.4766342529952402 to 0.41128571473111214, saving weights
Epoch 12/16
 804/1000 [=======================>......] - ETA: 1:55 - rpn_cls: 0.0660 - rpn_regr: 0.0129 - detector_cls: 0.1992 - detector_regr: 0.1081Average number of overlapping bounding boxes from RPN = 4.682 for 1000 previous iterations
1000/1000 [==============================] - 590s 590ms/step - rpn_cls: 0.0618 - rpn_regr: 0.0128 - detector_cls: 0.2007 - detector_regr: 0.1090
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.667
Classifier accuracy for bounding boxes from RPN: 0.921625
Loss RPN classifier: 0.061764341024293616
Loss RPN regression: 0.012789301411663474
Loss Detector classifier: 0.20068410071730614
Loss Detector regression: 0.10895055699069053
Elapsed time: 590.250209569931
Total loss decreased from 0.41128571473111214 to 0.3841883001439538, saving weights
Epoch 13/16
 804/1000 [=======================>......] - ETA: 1:55 - rpn_cls: 0.1522 - rpn_regr: 0.0125 - detector_cls: 0.1899 - detector_regr: 0.1051Average number of overlapping bounding boxes from RPN = 4.504 for 1000 previous iterations
1000/1000 [==============================] - 591s 591ms/step - rpn_cls: 0.1343 - rpn_regr: 0.0124 - detector_cls: 0.1902 - detector_regr: 0.1058
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.53
Classifier accuracy for bounding boxes from RPN: 0.92446875
Loss RPN classifier: 0.13428388184445833
Loss RPN regression: 0.01240205116791185
Loss Detector classifier: 0.19016670864168556
Loss Detector regression: 0.1058399659045972
Elapsed time: 591.8888745307922
Epoch 14/16
 804/1000 [=======================>......] - ETA: 1:54 - rpn_cls: 0.0989 - rpn_regr: 0.0117 - detector_cls: 0.1871 - detector_regr: 0.1009Average number of overlapping bounding boxes from RPN = 4.612 for 1000 previous iterations
1000/1000 [==============================] - 590s 590ms/step - rpn_cls: 0.1036 - rpn_regr: 0.0122 - detector_cls: 0.1932 - detector_regr: 0.1019
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.592
Classifier accuracy for bounding boxes from RPN: 0.92134375
Loss RPN classifier: 0.1036411218488062
Loss RPN regression: 0.012178868388487899
Loss Detector classifier: 0.19322462087683379
Loss Detector regression: 0.10187579123726755
Elapsed time: 590.2353308200836
Epoch 15/16
 804/1000 [=======================>......] - ETA: 1:55 - rpn_cls: 0.1305 - rpn_regr: 0.0124 - detector_cls: 0.1952 - detector_regr: 0.1047Average number of overlapping bounding boxes from RPN = 4.592 for 1000 previous iterations
1000/1000 [==============================] - 587s 587ms/step - rpn_cls: 0.1206 - rpn_regr: 0.0122 - detector_cls: 0.1930 - detector_regr: 0.1048
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.591
Classifier accuracy for bounding boxes from RPN: 0.92553125
Loss RPN classifier: 0.12055502655241196
Loss RPN regression: 0.012162947646997053
Loss Detector classifier: 0.1930431375913322
Loss Detector regression: 0.10481006521265954
Elapsed time: 586.9674727916718
Epoch 16/16
 804/1000 [=======================>......] - ETA: 1:54 - rpn_cls: 0.0882 - rpn_regr: 0.0127 - detector_cls: 0.1918 - detector_regr: 0.1025Average number of overlapping bounding boxes from RPN = 4.672 for 1000 previous iterations
1000/1000 [==============================] - 587s 587ms/step - rpn_cls: 0.0892 - rpn_regr: 0.0129 - detector_cls: 0.1917 - detector_regr: 0.1011
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.71
Classifier accuracy for bounding boxes from RPN: 0.92109375
Loss RPN classifier: 0.08921174746790303
Loss RPN regression: 0.0128684699260848
Loss Detector classifier: 0.19173618306033313
Loss Detector regression: 0.10108350288216025
Elapsed time: 587.0196466445923
Training complete, exiting.

#1차시도 -> 실패
# GPU 사용으로 인한 12시간 max 타임에 걸려서
# 에폭 18/30 수행함. 모델 만들어지지 않음.
# 줄여서 다시 해보기로 함.
# 일단 로그는 저장
Using TensorFlow backend.
Parsing annotation files
Training images per class:
{'bg': 0,
 'shape_a': 560,
 'shape_e': 532,
 'shape_eu': 552,
 'shape_i': 518,
 'shape_none': 600,
 'shape_o': 590,
 'shape_u': 600,
 'shape_ui': 598}
Num classes (including bg) = 9
Config has been written to config.pickle, and can be loaded when testing to ensure correct results
Num train samples 4120
Num val samples 430
WARNING: Logging before flag parsing goes to stderr.
W0823 19:09:08.959119 139763611248512 deprecation_wrapper.py:119] From /usr/local/lib/python3.6/dist-packages/keras/backend/tensorflow_backend.py:72: The name tf.get_default_graph is deprecated. Please use tf.compat.v1.get_default_graph instead.

W0823 19:09:08.976230 139763611248512 deprecation_wrapper.py:119] From /usr/local/lib/python3.6/dist-packages/keras/backend/tensorflow_backend.py:515: The name tf.placeholder is deprecated. Please use tf.compat.v1.placeholder instead.

W0823 19:09:08.983129 139763611248512 deprecation_wrapper.py:119] From /usr/local/lib/python3.6/dist-packages/keras/backend/tensorflow_backend.py:4048: The name tf.random_uniform is deprecated. Please use tf.random.uniform instead.

W0823 19:09:09.031012 139763611248512 deprecation_wrapper.py:119] From /usr/local/lib/python3.6/dist-packages/keras/backend/tensorflow_backend.py:1897: The name tf.nn.fused_batch_norm is deprecated. Please use tf.compat.v1.nn.fused_batch_norm instead.

W0823 19:09:09.033204 139763611248512 deprecation_wrapper.py:119] From /usr/local/lib/python3.6/dist-packages/keras/backend/tensorflow_backend.py:3878: The name tf.nn.max_pool is deprecated. Please use tf.nn.max_pool2d instead.

W0823 19:09:10.672168 139763611248512 deprecation_wrapper.py:119] From /usr/local/lib/python3.6/dist-packages/keras/backend/tensorflow_backend.py:4025: The name tf.random_normal is deprecated. Please use tf.random.normal instead.

W0823 19:09:10.724530 139763611248512 deprecation_wrapper.py:119] From /content/gdrive/My Drive/keras-frcnn/keras_frcnn/RoiPoolingConv.py:105: The name tf.image.resize_images is deprecated. Please use tf.image.resize instead.

W0823 19:09:12.053198 139763611248512 deprecation_wrapper.py:119] From /usr/local/lib/python3.6/dist-packages/keras/backend/tensorflow_backend.py:3882: The name tf.nn.avg_pool is deprecated. Please use tf.nn.avg_pool2d instead.

loading weights from resnet50_weights_tf_dim_ordering_tf_kernels.h5
Could not load pretrained model weights. Weights can be found in the keras application folder 		https://github.com/fchollet/keras/tree/master/keras/applications
W0823 19:09:12.137161 139763611248512 deprecation_wrapper.py:119] From /usr/local/lib/python3.6/dist-packages/keras/optimizers.py:782: The name tf.train.Optimizer is deprecated. Please use tf.compat.v1.train.Optimizer instead.

W0823 19:09:12.152150 139763611248512 deprecation_wrapper.py:119] From /usr/local/lib/python3.6/dist-packages/keras/backend/tensorflow_backend.py:3299: The name tf.log is deprecated. Please use tf.math.log instead.

W0823 19:09:12.156589 139763611248512 deprecation.py:323] From /usr/local/lib/python3.6/dist-packages/tensorflow/python/ops/nn_impl.py:180: add_dispatch_support.<locals>.wrapper (from tensorflow.python.ops.array_ops) is deprecated and will be removed in a future version.
Instructions for updating:
Use tf.where in 2.0, which has the same broadcast rule as np.where
Starting training
Epoch 1/30
2019-08-23 19:09:16.149553: I tensorflow/core/platform/profile_utils/cpu_utils.cc:94] CPU Frequency: 2300000000 Hz
2019-08-23 19:09:16.149862: I tensorflow/compiler/xla/service/service.cc:168] XLA service 0x1372d80 executing computations on platform Host. Devices:
2019-08-23 19:09:16.149896: I tensorflow/compiler/xla/service/service.cc:175]   StreamExecutor device (0): <undefined>, <undefined>
2019-08-23 19:09:16.152033: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcuda.so.1
2019-08-23 19:09:16.247875: I tensorflow/stream_executor/cuda/cuda_gpu_executor.cc:1005] successful NUMA node read from SysFS had negative value (-1), but there must be at least one NUMA node, so returning NUMA node zero
2019-08-23 19:09:16.248507: I tensorflow/compiler/xla/service/service.cc:168] XLA service 0x771b500 executing computations on platform CUDA. Devices:
2019-08-23 19:09:16.248569: I tensorflow/compiler/xla/service/service.cc:175]   StreamExecutor device (0): Tesla K80, Compute Capability 3.7
2019-08-23 19:09:16.248825: I tensorflow/stream_executor/cuda/cuda_gpu_executor.cc:1005] successful NUMA node read from SysFS had negative value (-1), but there must be at least one NUMA node, so returning NUMA node zero
2019-08-23 19:09:16.249348: I tensorflow/core/common_runtime/gpu/gpu_device.cc:1640] Found device 0 with properties:
name: Tesla K80 major: 3 minor: 7 memoryClockRate(GHz): 0.8235
pciBusID: 0000:00:04.0
2019-08-23 19:09:16.249663: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcudart.so.10.0
2019-08-23 19:09:16.251209: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcublas.so.10.0
2019-08-23 19:09:16.252586: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcufft.so.10.0
2019-08-23 19:09:16.252902: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcurand.so.10.0
2019-08-23 19:09:16.254747: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcusolver.so.10.0
2019-08-23 19:09:16.256209: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcusparse.so.10.0
2019-08-23 19:09:16.260380: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcudnn.so.7
2019-08-23 19:09:16.260553: I tensorflow/stream_executor/cuda/cuda_gpu_executor.cc:1005] successful NUMA node read from SysFS had negative value (-1), but there must be at least one NUMA node, so returning NUMA node zero
2019-08-23 19:09:16.261110: I tensorflow/stream_executor/cuda/cuda_gpu_executor.cc:1005] successful NUMA node read from SysFS had negative value (-1), but there must be at least one NUMA node, so returning NUMA node zero
2019-08-23 19:09:16.261592: I tensorflow/core/common_runtime/gpu/gpu_device.cc:1763] Adding visible gpu devices: 0
2019-08-23 19:09:16.261674: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcudart.so.10.0
2019-08-23 19:09:16.262762: I tensorflow/core/common_runtime/gpu/gpu_device.cc:1181] Device interconnect StreamExecutor with strength 1 edge matrix:
2019-08-23 19:09:16.262795: I tensorflow/core/common_runtime/gpu/gpu_device.cc:1187]      0
2019-08-23 19:09:16.262827: I tensorflow/core/common_runtime/gpu/gpu_device.cc:1200] 0:   N
2019-08-23 19:09:16.263231: I tensorflow/stream_executor/cuda/cuda_gpu_executor.cc:1005] successful NUMA node read from SysFS had negative value (-1), but there must be at least one NUMA node, so returning NUMA node zero
2019-08-23 19:09:16.263728: I tensorflow/stream_executor/cuda/cuda_gpu_executor.cc:1005] successful NUMA node read from SysFS had negative value (-1), but there must be at least one NUMA node, so returning NUMA node zero
2019-08-23 19:09:16.264130: W tensorflow/core/common_runtime/gpu/gpu_bfc_allocator.cc:40] Overriding allow_growth setting because the TF_FORCE_GPU_ALLOW_GROWTH environment variable is set. Original config value was 0.
2019-08-23 19:09:16.264191: I tensorflow/core/common_runtime/gpu/gpu_device.cc:1326] Created TensorFlow device (/job:localhost/replica:0/task:0/device:GPU:0 with 10802 MB memory) -> physical GPU (device: 0, name: Tesla K80, pci bus id: 0000:00:04.0, compute capability: 3.7)
2019-08-23 19:09:21.551370: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcudnn.so.7
2019-08-23 19:09:36.386202: I tensorflow/stream_executor/platform/default/dso_loader.cc:42] Successfully opened dynamic library libcublas.so.10.0
  59/1000 [>.............................] - ETA: 28:37 - rpn_cls: 1.9569 - rpn_regr: 0.0969 - detector_cls: 0.2049 - detector_regr: 0.2113Exception: 'a' cannot be empty unless no samples are taken
 275/1000 [=======>......................] - ETA: 20:08 - rpn_cls: 2.0643 - rpn_regr: 0.0628 - detector_cls: 0.1401 - detector_regr: 0.1630Exception: 'a' cannot be empty unless no samples are taken
 312/1000 [========>.....................] - ETA: 19:07 - rpn_cls: 2.0488 - rpn_regr: 0.0592 - detector_cls: 0.1367 - detector_regr: 0.1572Exception: 'a' cannot be empty unless no samples are taken
 320/1000 [========>.....................] - ETA: 18:50 - rpn_cls: 2.0735 - rpn_regr: 0.0587 - detector_cls: 0.1338 - detector_regr: 0.1533Exception: 'a' cannot be empty unless no samples are taken
 329/1000 [========>.....................] - ETA: 18:36 - rpn_cls: 2.0566 - rpn_regr: 0.0577 - detector_cls: 0.1367 - detector_regr: 0.1523Exception: 'a' cannot be empty unless no samples are taken
 352/1000 [=========>....................] - ETA: 18:08 - rpn_cls: 2.0416 - rpn_regr: 0.0562 - detector_cls: 0.1346 - detector_regr: 0.1472Exception: 'a' cannot be empty unless no samples are taken
 387/1000 [==========>...................] - ETA: 17:00 - rpn_cls: 2.0102 - rpn_regr: 0.0543 - detector_cls: 0.1320 - detector_regr: 0.1440Exception: 'a' cannot be empty unless no samples are taken
 401/1000 [===========>..................] - ETA: 16:39 - rpn_cls: 2.0372 - rpn_regr: 0.0540 - detector_cls: 0.1312 - detector_regr: 0.1453Exception: 'a' cannot be empty unless no samples are taken
 500/1000 [==============>...............] - ETA: 14:01 - rpn_cls: 2.0025 - rpn_regr: 0.0525 - detector_cls: 0.1325 - detector_regr: 0.1412Exception: 'a' cannot be empty unless no samples are taken
 559/1000 [===============>..............] - ETA: 12:18 - rpn_cls: 1.9729 - rpn_regr: 0.0511 - detector_cls: 0.1272 - detector_regr: 0.1353Exception: 'a' cannot be empty unless no samples are taken
 712/1000 [====================>.........] - ETA: 7:57 - rpn_cls: 1.8559 - rpn_regr: 0.0499 - detector_cls: 0.1202 - detector_regr: 0.1329Exception: 'a' cannot be empty unless no samples are taken
 725/1000 [====================>.........] - ETA: 7:37 - rpn_cls: 1.8407 - rpn_regr: 0.0501 - detector_cls: 0.1210 - detector_regr: 0.1347Exception: 'a' cannot be empty unless no samples are taken
 795/1000 [======================>.......] - ETA: 5:38 - rpn_cls: 1.8166 - rpn_regr: 0.0486 - detector_cls: 0.1172 - detector_regr: 0.1304Exception: 'a' cannot be empty unless no samples are taken
 800/1000 [=======================>......] - ETA: 5:30 - rpn_cls: 1.8107 - rpn_regr: 0.0485 - detector_cls: 0.1170 - detector_regr: 0.1300Average number of overlapping bounding boxes from RPN = 0.413 for 1000 previous iterations
 844/1000 [========================>.....] - ETA: 4:17 - rpn_cls: 1.7982 - rpn_regr: 0.0484 - detector_cls: 0.1129 - detector_regr: 0.1255Exception: 'a' cannot be empty unless no samples are taken
 870/1000 [=========================>....] - ETA: 3:34 - rpn_cls: 1.7794 - rpn_regr: 0.0485 - detector_cls: 0.1109 - detector_regr: 0.1236Exception: 'a' cannot be empty unless no samples are taken
 875/1000 [=========================>....] - ETA: 3:26 - rpn_cls: 1.7741 - rpn_regr: 0.0483 - detector_cls: 0.1104 - detector_regr: 0.1233Exception: 'a' cannot be empty unless no samples are taken
 898/1000 [=========================>....] - ETA: 2:48 - rpn_cls: 1.7844 - rpn_regr: 0.0478 - detector_cls: 0.1093 - detector_regr: 0.1230Exception: 'a' cannot be empty unless no samples are taken
 949/1000 [===========================>..] - ETA: 1:23 - rpn_cls: 1.7762 - rpn_regr: 0.0477 - detector_cls: 0.1082 - detector_regr: 0.1227Exception: 'a' cannot be empty unless no samples are taken
1000/1000 [==============================] - 1632s 2s/step - rpn_cls: 1.7533 - rpn_regr: 0.0467 - detector_cls: 0.1162 - detector_regr: 0.1268
Mean number of bounding boxes from RPN overlapping ground truth boxes: 0.4344660194174757
Classifier accuracy for bounding boxes from RPN: 0.983
Loss RPN classifier: 1.7533449420030633
Loss RPN regression: 0.046723479873006
Loss Detector classifier: 0.11624048326509324
Loss Detector regression: 0.1267649987526238
Elapsed time: 1631.6978178024292
Total loss decreased from inf to 2.043073903893786, saving weights
Epoch 2/30
 181/1000 [====>.........................] - ETA: 19:24 - rpn_cls: 1.4384 - rpn_regr: 0.0343 - detector_cls: 0.2603 - detector_regr: 0.2428Exception: 'a' cannot be empty unless no samples are taken
 190/1000 [====>.........................] - ETA: 19:34 - rpn_cls: 1.4444 - rpn_regr: 0.0363 - detector_cls: 0.2573 - detector_regr: 0.2446Exception: 'a' cannot be empty unless no samples are taken
 234/1000 [======>.......................] - ETA: 18:20 - rpn_cls: 1.4115 - rpn_regr: 0.0348 - detector_cls: 0.2498 - detector_regr: 0.2403Exception: 'a' cannot be empty unless no samples are taken
 251/1000 [======>.......................] - ETA: 18:01 - rpn_cls: 1.3878 - rpn_regr: 0.0344 - detector_cls: 0.2480 - detector_regr: 0.2376Exception: 'a' cannot be empty unless no samples are taken
 299/1000 [=======>......................] - ETA: 17:04 - rpn_cls: 1.4263 - rpn_regr: 0.0364 - detector_cls: 0.2417 - detector_regr: 0.2341Exception: 'a' cannot be empty unless no samples are taken
 300/1000 [========>.....................] - ETA: 17:04 - rpn_cls: 1.4216 - rpn_regr: 0.0363 - detector_cls: 0.2411 - detector_regr: 0.2333Exception: 'a' cannot be empty unless no samples are taken
 305/1000 [========>.....................] - ETA: 16:58 - rpn_cls: 1.4125 - rpn_regr: 0.0361 - detector_cls: 0.2397 - detector_regr: 0.2314Exception: 'a' cannot be empty unless no samples are taken
 306/1000 [========>.....................] - ETA: 16:58 - rpn_cls: 1.4221 - rpn_regr: 0.0360 - detector_cls: 0.2411 - detector_regr: 0.2316Exception: 'a' cannot be empty unless no samples are taken
 342/1000 [=========>....................] - ETA: 16:12 - rpn_cls: 1.3784 - rpn_regr: 0.0363 - detector_cls: 0.2318 - detector_regr: 0.2272Exception: 'a' cannot be empty unless no samples are taken
Exception: 'a' cannot be empty unless no samples are taken
 421/1000 [===========>..................] - ETA: 14:23 - rpn_cls: 1.3670 - rpn_regr: 0.0367 - detector_cls: 0.2222 - detector_regr: 0.2192Exception: 'a' cannot be empty unless no samples are taken
 432/1000 [===========>..................] - ETA: 14:12 - rpn_cls: 1.3973 - rpn_regr: 0.0364 - detector_cls: 0.2233 - detector_regr: 0.2211Exception: 'a' cannot be empty unless no samples are taken
 449/1000 [============>.................] - ETA: 13:49 - rpn_cls: 1.3754 - rpn_regr: 0.0365 - detector_cls: 0.2196 - detector_regr: 0.2171Exception: 'a' cannot be empty unless no samples are taken
Exception: 'a' cannot be empty unless no samples are taken
 467/1000 [=============>................] - ETA: 13:30 - rpn_cls: 1.3835 - rpn_regr: 0.0363 - detector_cls: 0.2179 - detector_regr: 0.2168Exception: 'a' cannot be empty unless no samples are taken
 562/1000 [===============>..............] - ETA: 11:06 - rpn_cls: 1.2925 - rpn_regr: 0.0361 - detector_cls: 0.2125 - detector_regr: 0.2122Exception: 'a' cannot be empty unless no samples are taken
 575/1000 [================>.............] - ETA: 10:49 - rpn_cls: 1.3005 - rpn_regr: 0.0364 - detector_cls: 0.2111 - detector_regr: 0.2112Exception: 'a' cannot be empty unless no samples are taken
 597/1000 [================>.............] - ETA: 10:16 - rpn_cls: 1.2994 - rpn_regr: 0.0361 - detector_cls: 0.2085 - detector_regr: 0.2086Exception: 'a' cannot be empty unless no samples are taken
 623/1000 [=================>............] - ETA: 9:39 - rpn_cls: 1.2993 - rpn_regr: 0.0359 - detector_cls: 0.2078 - detector_regr: 0.2079Exception: 'a' cannot be empty unless no samples are taken
 627/1000 [=================>............] - ETA: 9:33 - rpn_cls: 1.2983 - rpn_regr: 0.0363 - detector_cls: 0.2078 - detector_regr: 0.2086Exception: 'a' cannot be empty unless no samples are taken
 641/1000 [==================>...........] - ETA: 9:13 - rpn_cls: 1.2704 - rpn_regr: 0.0360 - detector_cls: 0.2083 - detector_regr: 0.2079Exception: 'a' cannot be empty unless no samples are taken
 655/1000 [==================>...........] - ETA: 8:51 - rpn_cls: 1.2727 - rpn_regr: 0.0364 - detector_cls: 0.2069 - detector_regr: 0.2061Exception: 'a' cannot be empty unless no samples are taken
 658/1000 [==================>...........] - ETA: 8:47 - rpn_cls: 1.2748 - rpn_regr: 0.0363 - detector_cls: 0.2066 - detector_regr: 0.2055Average number of overlapping bounding boxes from RPN = 0.975 for 1000 previous iterations
 669/1000 [===================>..........] - ETA: 8:31 - rpn_cls: 1.2730 - rpn_regr: 0.0363 - detector_cls: 0.2063 - detector_regr: 0.2048Exception: 'a' cannot be empty unless no samples are taken
 681/1000 [===================>..........] - ETA: 8:13 - rpn_cls: 1.2872 - rpn_regr: 0.0360 - detector_cls: 0.2067 - detector_regr: 0.2045Exception: 'a' cannot be empty unless no samples are taken
 737/1000 [=====================>........] - ETA: 6:47 - rpn_cls: 1.3013 - rpn_regr: 0.0357 - detector_cls: 0.2062 - detector_regr: 0.2029Exception: 'a' cannot be empty unless no samples are taken
 752/1000 [=====================>........] - ETA: 6:23 - rpn_cls: 1.2946 - rpn_regr: 0.0357 - detector_cls: 0.2070 - detector_regr: 0.2043Exception: 'a' cannot be empty unless no samples are taken
Exception: 'a' cannot be empty unless no samples are taken
 804/1000 [=======================>......] - ETA: 5:02 - rpn_cls: 1.2652 - rpn_regr: 0.0356 - detector_cls: 0.2074 - detector_regr: 0.2041Exception: 'a' cannot be empty unless no samples are taken
Exception: 'a' cannot be empty unless no samples are taken
 821/1000 [=======================>......] - ETA: 4:36 - rpn_cls: 1.2529 - rpn_regr: 0.0356 - detector_cls: 0.2061 - detector_regr: 0.2038Exception: 'a' cannot be empty unless no samples are taken
 861/1000 [========================>.....] - ETA: 3:34 - rpn_cls: 1.2308 - rpn_regr: 0.0354 - detector_cls: 0.2039 - detector_regr: 0.2024Exception: 'a' cannot be empty unless no samples are taken
 887/1000 [=========================>....] - ETA: 2:53 - rpn_cls: 1.2335 - rpn_regr: 0.0354 - detector_cls: 0.2027 - detector_regr: 0.2014Exception: 'a' cannot be empty unless no samples are taken
 896/1000 [=========================>....] - ETA: 2:39 - rpn_cls: 1.2308 - rpn_regr: 0.0354 - detector_cls: 0.2032 - detector_regr: 0.2022Exception: 'a' cannot be empty unless no samples are taken
 901/1000 [==========================>...] - ETA: 2:32 - rpn_cls: 1.2240 - rpn_regr: 0.0354 - detector_cls: 0.2027 - detector_regr: 0.2024Exception: 'a' cannot be empty unless no samples are taken
 941/1000 [===========================>..] - ETA: 1:30 - rpn_cls: 1.2063 - rpn_regr: 0.0355 - detector_cls: 0.2021 - detector_regr: 0.2020Exception: 'a' cannot be empty unless no samples are taken
 950/1000 [===========================>..] - ETA: 1:17 - rpn_cls: 1.2086 - rpn_regr: 0.0353 - detector_cls: 0.2022 - detector_regr: 0.2017Exception: 'a' cannot be empty unless no samples are taken
 957/1000 [===========================>..] - ETA: 1:06 - rpn_cls: 1.1998 - rpn_regr: 0.0354 - detector_cls: 0.2019 - detector_regr: 0.2013Exception: 'a' cannot be empty unless no samples are taken
 990/1000 [============================>.] - ETA: 15s - rpn_cls: 1.1823 - rpn_regr: 0.0352 - detector_cls: 0.2002 - detector_regr: 0.1994Exception: 'a' cannot be empty unless no samples are taken
1000/1000 [==============================] - 1549s 2s/step - rpn_cls: 1.1705 - rpn_regr: 0.0351 - detector_cls: 0.2003 - detector_regr: 0.2003
Mean number of bounding boxes from RPN overlapping ground truth boxes: 1.1244598098530683
Classifier accuracy for bounding boxes from RPN: 0.96103125
Loss RPN classifier: 1.1705147738959663
Loss RPN regression: 0.035061021029221595
Loss Detector classifier: 0.20027804781938904
Loss Detector regression: 0.20025841663591565
Elapsed time: 1566.0965507030487
Total loss decreased from 2.043073903893786 to 1.6061122593804926, saving weights
Epoch 3/30
  18/1000 [..............................] - ETA: 23:44 - rpn_cls: 0.3778 - rpn_regr: 0.0211 - detector_cls: 0.1661 - detector_regr: 0.1960Exception: 'a' cannot be empty unless no samples are taken
  33/1000 [..............................] - ETA: 22:40 - rpn_cls: 0.4898 - rpn_regr: 0.0200 - detector_cls: 0.1940 - detector_regr: 0.2218Exception: 'a' cannot be empty unless no samples are taken
  34/1000 [>.............................] - ETA: 23:32 - rpn_cls: 0.6038 - rpn_regr: 0.0196 - detector_cls: 0.1885 - detector_regr: 0.2152Exception: 'a' cannot be empty unless no samples are taken
  35/1000 [>.............................] - ETA: 24:20 - rpn_cls: 0.5866 - rpn_regr: 0.0192 - detector_cls: 0.1834 - detector_regr: 0.2091Exception: 'a' cannot be empty unless no samples are taken
  68/1000 [=>............................] - ETA: 24:02 - rpn_cls: 0.9404 - rpn_regr: 0.0260 - detector_cls: 0.2152 - detector_regr: 0.2238Exception: 'a' cannot be empty unless no samples are taken
 124/1000 [==>...........................] - ETA: 22:46 - rpn_cls: 0.7525 - rpn_regr: 0.0283 - detector_cls: 0.2162 - detector_regr: 0.2263Exception: 'a' cannot be empty unless no samples are taken
 224/1000 [=====>........................] - ETA: 20:04 - rpn_cls: 0.8341 - rpn_regr: 0.0306 - detector_cls: 0.2380 - detector_regr: 0.2322Exception: 'a' cannot be empty unless no samples are taken
 225/1000 [=====>........................] - ETA: 20:06 - rpn_cls: 0.8377 - rpn_regr: 0.0311 - detector_cls: 0.2379 - detector_regr: 0.2328Exception: 'a' cannot be empty unless no samples are taken
 229/1000 [=====>........................] - ETA: 20:02 - rpn_cls: 0.8512 - rpn_regr: 0.0312 - detector_cls: 0.2375 - detector_regr: 0.2317Exception: 'a' cannot be empty unless no samples are taken
Exception: 'a' cannot be empty unless no samples are taken
 267/1000 [=======>......................] - ETA: 19:07 - rpn_cls: 0.8307 - rpn_regr: 0.0313 - detector_cls: 0.2359 - detector_regr: 0.2268Exception: 'a' cannot be empty unless no samples are taken
 284/1000 [=======>......................] - ETA: 18:41 - rpn_cls: 0.8126 - rpn_regr: 0.0314 - detector_cls: 0.2334 - detector_regr: 0.2271Exception: 'a' cannot be empty unless no samples are taken
 310/1000 [========>.....................] - ETA: 18:15 - rpn_cls: 0.8015 - rpn_regr: 0.0305 - detector_cls: 0.2391 - detector_regr: 0.2340Exception: 'a' cannot be empty unless no samples are taken
 311/1000 [========>.....................] - ETA: 18:14 - rpn_cls: 0.7989 - rpn_regr: 0.0305 - detector_cls: 0.2393 - detector_regr: 0.2341Exception: 'a' cannot be empty unless no samples are taken
 332/1000 [========>.....................] - ETA: 17:39 - rpn_cls: 0.8137 - rpn_regr: 0.0309 - detector_cls: 0.2389 - detector_regr: 0.2325Exception: 'a' cannot be empty unless no samples are taken
 366/1000 [=========>....................] - ETA: 16:50 - rpn_cls: 0.8522 - rpn_regr: 0.0301 - detector_cls: 0.2385 - detector_regr: 0.2326Exception: 'a' cannot be empty unless no samples are taken
 378/1000 [==========>...................] - ETA: 16:38 - rpn_cls: 0.8518 - rpn_regr: 0.0299 - detector_cls: 0.2392 - detector_regr: 0.2310Exception: 'a' cannot be empty unless no samples are taken
 392/1000 [==========>...................] - ETA: 16:19 - rpn_cls: 0.8550 - rpn_regr: 0.0297 - detector_cls: 0.2374 - detector_regr: 0.2317Exception: 'a' cannot be empty unless no samples are taken
Exception: 'a' cannot be empty unless no samples are taken
 394/1000 [==========>...................] - ETA: 16:17 - rpn_cls: 0.8617 - rpn_regr: 0.0296 - detector_cls: 0.2376 - detector_regr: 0.2320Exception: 'a' cannot be empty unless no samples are taken
 402/1000 [===========>..................] - ETA: 16:06 - rpn_cls: 0.8553 - rpn_regr: 0.0295 - detector_cls: 0.2374 - detector_regr: 0.2313Exception: 'a' cannot be empty unless no samples are taken
 403/1000 [===========>..................] - ETA: 16:06 - rpn_cls: 0.8640 - rpn_regr: 0.0294 - detector_cls: 0.2368 - detector_regr: 0.2307Exception: 'a' cannot be empty unless no samples are taken
 406/1000 [===========>..................] - ETA: 16:02 - rpn_cls: 0.8580 - rpn_regr: 0.0294 - detector_cls: 0.2358 - detector_regr: 0.2304Exception: 'a' cannot be empty unless no samples are taken
 408/1000 [===========>..................] - ETA: 15:59 - rpn_cls: 0.8538 - rpn_regr: 0.0293 - detector_cls: 0.2353 - detector_regr: 0.2297Exception: 'a' cannot be empty unless no samples are taken
 410/1000 [===========>..................] - ETA: 16:00 - rpn_cls: 0.8603 - rpn_regr: 0.0293 - detector_cls: 0.2365 - detector_regr: 0.2306Exception: 'a' cannot be empty unless no samples are taken
 449/1000 [============>.................] - ETA: 14:50 - rpn_cls: 0.8317 - rpn_regr: 0.0303 - detector_cls: 0.2409 - detector_regr: 0.2296Exception: 'a' cannot be empty unless no samples are taken
 450/1000 [============>.................] - ETA: 14:49 - rpn_cls: 0.8299 - rpn_regr: 0.0303 - detector_cls: 0.2404 - detector_regr: 0.2291Exception: 'a' cannot be empty unless no samples are taken
 453/1000 [============>.................] - ETA: 14:45 - rpn_cls: 0.8244 - rpn_regr: 0.0302 - detector_cls: 0.2401 - detector_regr: 0.2296Exception: 'a' cannot be empty unless no samples are taken
 456/1000 [============>.................] - ETA: 14:42 - rpn_cls: 0.8190 - rpn_regr: 0.0302 - detector_cls: 0.2400 - detector_regr: 0.2304Exception: 'a' cannot be empty unless no samples are taken
Exception: 'a' cannot be empty unless no samples are taken
 508/1000 [==============>...............] - ETA: 13:07 - rpn_cls: 0.8054 - rpn_regr: 0.0301 - detector_cls: 0.2453 - detector_regr: 0.2326Average number of overlapping bounding boxes from RPN = 1.468 for 1000 previous iterations
 753/1000 [=====================>........] - ETA: 6:20 - rpn_cls: 0.7685 - rpn_regr: 0.0290 - detector_cls: 0.2681 - detector_regr: 0.2384Exception: 'a' cannot be empty unless no samples are taken
 808/1000 [=======================>......] - ETA: 4:54 - rpn_cls: 0.7652 - rpn_regr: 0.0286 - detector_cls: 0.2697 - detector_regr: 0.2379Exception: 'a' cannot be empty unless no samples are taken
 874/1000 [=========================>....] - ETA: 3:12 - rpn_cls: 0.7851 - rpn_regr: 0.0280 - detector_cls: 0.2728 - detector_regr: 0.2366Exception: 'a' cannot be empty unless no samples are taken
 876/1000 [=========================>....] - ETA: 3:09 - rpn_cls: 0.7883 - rpn_regr: 0.0280 - detector_cls: 0.2730 - detector_regr: 0.2368Exception: 'a' cannot be empty unless no samples are taken
1000/1000 [==============================] - 1514s 2s/step - rpn_cls: 0.7901 - rpn_regr: 0.0280 - detector_cls: 0.2801 - detector_regr: 0.2366
Mean number of bounding boxes from RPN overlapping ground truth boxes: 2.093947606142728
Classifier accuracy for bounding boxes from RPN: 0.9311875
Loss RPN classifier: 0.7900940498340653
Loss RPN regression: 0.027997603707684903
Loss Detector classifier: 0.2800911515419757
Loss Detector regression: 0.23664783760532737
Elapsed time: 1514.7052445411682
Total loss decreased from 1.6061122593804926 to 1.3348306426890533, saving weights
Epoch 4/30
 500/1000 [==============>...............] - ETA: 11:39 - rpn_cls: 0.4381 - rpn_regr: 0.0212 - detector_cls: 0.3974 - detector_regr: 0.2233Average number of overlapping bounding boxes from RPN = 3.217 for 1000 previous iterations
1000/1000 [==============================] - 1327s 1s/step - rpn_cls: 0.3523 - rpn_regr: 0.0228 - detector_cls: 0.3813 - detector_regr: 0.2090
Mean number of bounding boxes from RPN overlapping ground truth boxes: 3.972
Classifier accuracy for bounding boxes from RPN: 0.88521875
Loss RPN classifier: 0.3523456276529752
Loss RPN regression: 0.02284885988253518
Loss Detector classifier: 0.38130533212795853
Loss Detector regression: 0.2089984074998647
Elapsed time: 1327.4295721054077
Total loss decreased from 1.3348306426890533 to 0.9654982271633337, saving weights
Epoch 5/30
 500/1000 [==============>...............] - ETA: 9:58 - rpn_cls: 0.4321 - rpn_regr: 0.0219 - detector_cls: 0.3276 - detector_regr: 0.1779Average number of overlapping bounding boxes from RPN = 4.101 for 1000 previous iterations
1000/1000 [==============================] - 1198s 1s/step - rpn_cls: 0.3698 - rpn_regr: 0.0210 - detector_cls: 0.3270 - detector_regr: 0.1719
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.221
Classifier accuracy for bounding boxes from RPN: 0.888875
Loss RPN classifier: 0.36976202109913775
Loss RPN regression: 0.020983538598316955
Loss Detector classifier: 0.32700754186930137
Loss Detector regression: 0.17192463271412997
Elapsed time: 1198.526334285736
Total loss decreased from 0.9654982271633337 to 0.889677734280886, saving weights
Epoch 6/30
 500/1000 [==============>...............] - ETA: 9:58 - rpn_cls: 0.2872 - rpn_regr: 0.0170 - detector_cls: 0.3123 - detector_regr: 0.1640Average number of overlapping bounding boxes from RPN = 4.36 for 1000 previous iterations
1000/1000 [==============================] - 1200s 1s/step - rpn_cls: 0.2852 - rpn_regr: 0.0176 - detector_cls: 0.2996 - detector_regr: 0.1582
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.34
Classifier accuracy for bounding boxes from RPN: 0.89534375
Loss RPN classifier: 0.2852023530111347
Loss RPN regression: 0.01761540567461634
Loss Detector classifier: 0.2996269857697189
Loss Detector regression: 0.1582454919065349
Elapsed time: 1200.2867925167084
Total loss decreased from 0.889677734280886 to 0.7606902363620048, saving weights
Epoch 7/30
 500/1000 [==============>...............] - ETA: 10:00 - rpn_cls: 0.1810 - rpn_regr: 0.0179 - detector_cls: 0.2644 - detector_regr: 0.1492Average number of overlapping bounding boxes from RPN = 4.275 for 1000 previous iterations
1000/1000 [==============================] - 1195s 1s/step - rpn_cls: 0.1706 - rpn_regr: 0.0165 - detector_cls: 0.2527 - detector_regr: 0.1422
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.193
Classifier accuracy for bounding boxes from RPN: 0.9075625
Loss RPN classifier: 0.17058742602418955
Loss RPN regression: 0.016528963487551663
Loss Detector classifier: 0.2527467174325138
Loss Detector regression: 0.14215089913271367
Elapsed time: 1195.6417126655579
Total loss decreased from 0.7606902363620048 to 0.5820140060769687, saving weights
Epoch 8/30
 500/1000 [==============>...............] - ETA: 9:53 - rpn_cls: 0.1200 - rpn_regr: 0.0144 - detector_cls: 0.2374 - detector_regr: 0.1363Average number of overlapping bounding boxes from RPN = 4.197 for 1000 previous iterations
1000/1000 [==============================] - 1188s 1s/step - rpn_cls: 0.1284 - rpn_regr: 0.0147 - detector_cls: 0.2365 - detector_regr: 0.1328
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.226
Classifier accuracy for bounding boxes from RPN: 0.91096875
Loss RPN classifier: 0.12843744032671736
Loss RPN regression: 0.014655288683003163
Loss Detector classifier: 0.23653077100589873
Loss Detector regression: 0.13284638916701078
Elapsed time: 1188.3321959972382
Total loss decreased from 0.5820140060769687 to 0.51246988918263, saving weights
Epoch 9/30
 500/1000 [==============>...............] - ETA: 9:51 - rpn_cls: 0.1556 - rpn_regr: 0.0158 - detector_cls: 0.2194 - detector_regr: 0.1291Average number of overlapping bounding boxes from RPN = 4.217 for 1000 previous iterations
1000/1000 [==============================] - 1183s 1s/step - rpn_cls: 0.1426 - rpn_regr: 0.0158 - detector_cls: 0.2201 - detector_regr: 0.1300
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.288
Classifier accuracy for bounding boxes from RPN: 0.9191875
Loss RPN classifier: 0.14257219724387313
Loss RPN regression: 0.015822239190714755
Loss Detector classifier: 0.22013872766261922
Loss Detector regression: 0.12998562338761985
Elapsed time: 1183.2025072574615
Total loss decreased from 0.51246988918263 to 0.5085187874848269, saving weights
Epoch 10/30
 500/1000 [==============>...............] - ETA: 9:50 - rpn_cls: 0.1075 - rpn_regr: 0.0134 - detector_cls: 0.2095 - detector_regr: 0.1259Average number of overlapping bounding boxes from RPN = 4.359 for 1000 previous iterations
1000/1000 [==============================] - 1183s 1s/step - rpn_cls: 0.0907 - rpn_regr: 0.0133 - detector_cls: 0.2139 - detector_regr: 0.1252
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.39
Classifier accuracy for bounding boxes from RPN: 0.9199375
Loss RPN classifier: 0.09071712274105843
Loss RPN regression: 0.013278957593429367
Loss Detector classifier: 0.21387047112639992
Loss Detector regression: 0.12517282254248857
Elapsed time: 1183.608183145523
Total loss decreased from 0.5085187874848269 to 0.4430393740033763, saving weights
Epoch 11/30
 500/1000 [==============>...............] - ETA: 9:50 - rpn_cls: 0.1339 - rpn_regr: 0.0130 - detector_cls: 0.2009 - detector_regr: 0.1228Average number of overlapping bounding boxes from RPN = 4.423 for 1000 previous iterations
1000/1000 [==============================] - 1177s 1s/step - rpn_cls: 0.1120 - rpn_regr: 0.0130 - detector_cls: 0.1962 - detector_regr: 0.1201
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.43
Classifier accuracy for bounding boxes from RPN: 0.92371875
Loss RPN classifier: 0.11201754032767532
Loss RPN regression: 0.013036662160906418
Loss Detector classifier: 0.19618703436944634
Loss Detector regression: 0.12005537033919245
Elapsed time: 1177.5753977298737
Total loss decreased from 0.4430393740033763 to 0.4412966071972205, saving weights
Epoch 12/30
 500/1000 [==============>...............] - ETA: 9:48 - rpn_cls: 0.1095 - rpn_regr: 0.0134 - detector_cls: 0.2028 - detector_regr: 0.1137Average number of overlapping bounding boxes from RPN = 4.514 for 1000 previous iterations
1000/1000 [==============================] - 1178s 1s/step - rpn_cls: 0.0860 - rpn_regr: 0.0133 - detector_cls: 0.1958 - detector_regr: 0.1125
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.527
Classifier accuracy for bounding boxes from RPN: 0.9235
Loss RPN classifier: 0.08596931890827664
Loss RPN regression: 0.01327312182757305
Loss Detector classifier: 0.19582468541525305
Loss Detector regression: 0.11254614771762862
Elapsed time: 1178.5225086212158
Total loss decreased from 0.4412966071972205 to 0.40761327386873136, saving weights
Epoch 13/30
 500/1000 [==============>...............] - ETA: 9:48 - rpn_cls: 0.0502 - rpn_regr: 0.0112 - detector_cls: 0.1982 - detector_regr: 0.1117Average number of overlapping bounding boxes from RPN = 4.491 for 1000 previous iterations
1000/1000 [==============================] - 1181s 1s/step - rpn_cls: 0.1130 - rpn_regr: 0.0114 - detector_cls: 0.1946 - detector_regr: 0.1124
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.592
Classifier accuracy for bounding boxes from RPN: 0.9255
Loss RPN classifier: 0.11304672675534533
Loss RPN regression: 0.011364717209726222
Loss Detector classifier: 0.1946129861921072
Loss Detector regression: 0.11237953047640621
Elapsed time: 1181.5733127593994
Epoch 14/30
 500/1000 [==============>...............] - ETA: 9:48 - rpn_cls: 0.0550 - rpn_regr: 0.0129 - detector_cls: 0.1888 - detector_regr: 0.1084Average number of overlapping bounding boxes from RPN = 4.631 for 1000 previous iterations
1000/1000 [==============================] - 1176s 1s/step - rpn_cls: 0.0529 - rpn_regr: 0.0122 - detector_cls: 0.1790 - detector_regr: 0.1074
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.526
Classifier accuracy for bounding boxes from RPN: 0.928
Loss RPN classifier: 0.05291135361284409
Loss RPN regression: 0.012211065563431475
Loss Detector classifier: 0.17898283801041542
Loss Detector regression: 0.10739262754330411
Elapsed time: 1175.6671690940857
Total loss decreased from 0.40761327386873136 to 0.3514978847299951, saving weights
Epoch 15/30
 500/1000 [==============>...............] - ETA: 9:48 - rpn_cls: 0.0946 - rpn_regr: 0.0121 - detector_cls: 0.1792 - detector_regr: 0.1052Average number of overlapping bounding boxes from RPN = 4.528 for 1000 previous iterations
1000/1000 [==============================] - 1175s 1s/step - rpn_cls: 0.0835 - rpn_regr: 0.0123 - detector_cls: 0.1814 - detector_regr: 0.1082
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.567
Classifier accuracy for bounding boxes from RPN: 0.929625
Loss RPN classifier: 0.08346273674510624
Loss RPN regression: 0.012264760338090127
Loss Detector classifier: 0.18144172688480467
Loss Detector regression: 0.1081976878521964
Elapsed time: 1175.355320930481
Epoch 16/30
 500/1000 [==============>...............] - ETA: 9:45 - rpn_cls: 0.0860 - rpn_regr: 0.0120 - detector_cls: 0.1905 - detector_regr: 0.1129Average number of overlapping bounding boxes from RPN = 4.655 for 1000 previous iterations
1000/1000 [==============================] - 1170s 1s/step - rpn_cls: 0.0625 - rpn_regr: 0.0123 - detector_cls: 0.1956 - detector_regr: 0.1108
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.825
Classifier accuracy for bounding boxes from RPN: 0.921875
Loss RPN classifier: 0.062488714537392
Loss RPN regression: 0.01228582869566162
Loss Detector classifier: 0.19558007343299688
Loss Detector regression: 0.11084113984834403
Elapsed time: 1170.3801629543304
Epoch 17/30
 500/1000 [==============>...............] - ETA: 9:43 - rpn_cls: 0.1112 - rpn_regr: 0.0115 - detector_cls: 0.1834 - detector_regr: 0.1040Average number of overlapping bounding boxes from RPN = 4.831 for 1000 previous iterations
1000/1000 [==============================] - 1166s 1s/step - rpn_cls: 0.0888 - rpn_regr: 0.0113 - detector_cls: 0.1768 - detector_regr: 0.1010
Mean number of bounding boxes from RPN overlapping ground truth boxes: 4.784
Classifier accuracy for bounding boxes from RPN: 0.92784375
Loss RPN classifier: 0.08877437161920836
Loss RPN regression: 0.011292990233610908
Loss Detector classifier: 0.1767943933773786
Loss Detector regression: 0.10098005435289815
Elapsed time: 1166.283566236496
