# generated from rosidl_generator_py/resource/_idl.py.em
# with input from rero_ros:msg/Slot.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Slot(type):
    """Metaclass of message 'Slot'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('rero_ros')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'rero_ros.msg.Slot')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__slot
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__slot
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__slot
            cls._TYPE_SUPPORT = module.type_support_msg__msg__slot
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__slot

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Slot(metaclass=Metaclass_Slot):
    """Message class 'Slot'."""

    __slots__ = [
        '_raw_value',
        '_entity',
        '_slot_name',
        '_range_start',
        '_range_end',
        '_type_name',
        '_type_value',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'raw_value': 'string',
        'entity': 'string',
        'slot_name': 'string',
        'range_start': 'uint16',
        'range_end': 'uint16',
        'type_name': 'string',
        'type_value': 'string',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        if 'check_fields' in kwargs:
            self._check_fields = kwargs['check_fields']
        else:
            self._check_fields = ros_python_check_fields == '1'
        if self._check_fields:
            assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
                'Invalid arguments passed to constructor: %s' % \
                ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.raw_value = kwargs.get('raw_value', str())
        self.entity = kwargs.get('entity', str())
        self.slot_name = kwargs.get('slot_name', str())
        self.range_start = kwargs.get('range_start', int())
        self.range_end = kwargs.get('range_end', int())
        self.type_name = kwargs.get('type_name', str())
        self.type_value = kwargs.get('type_value', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    if self._check_fields:
                        assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.raw_value != other.raw_value:
            return False
        if self.entity != other.entity:
            return False
        if self.slot_name != other.slot_name:
            return False
        if self.range_start != other.range_start:
            return False
        if self.range_end != other.range_end:
            return False
        if self.type_name != other.type_name:
            return False
        if self.type_value != other.type_value:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def raw_value(self):
        """Message field 'raw_value'."""
        return self._raw_value

    @raw_value.setter
    def raw_value(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'raw_value' field must be of type 'str'"
        self._raw_value = value

    @builtins.property
    def entity(self):
        """Message field 'entity'."""
        return self._entity

    @entity.setter
    def entity(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'entity' field must be of type 'str'"
        self._entity = value

    @builtins.property
    def slot_name(self):
        """Message field 'slot_name'."""
        return self._slot_name

    @slot_name.setter
    def slot_name(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'slot_name' field must be of type 'str'"
        self._slot_name = value

    @builtins.property
    def range_start(self):
        """Message field 'range_start'."""
        return self._range_start

    @range_start.setter
    def range_start(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'range_start' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'range_start' field must be an unsigned integer in [0, 65535]"
        self._range_start = value

    @builtins.property
    def range_end(self):
        """Message field 'range_end'."""
        return self._range_end

    @range_end.setter
    def range_end(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'range_end' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'range_end' field must be an unsigned integer in [0, 65535]"
        self._range_end = value

    @builtins.property
    def type_name(self):
        """Message field 'type_name'."""
        return self._type_name

    @type_name.setter
    def type_name(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'type_name' field must be of type 'str'"
        self._type_name = value

    @builtins.property
    def type_value(self):
        """Message field 'type_value'."""
        return self._type_value

    @type_value.setter
    def type_value(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'type_value' field must be of type 'str'"
        self._type_value = value
