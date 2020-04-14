import React, { Fragment } from 'react';
import {
  Text
} from 'react-native';


const MyFirstFunctionalComponent = (props) => {
    
    return(
        <Fragment>
            <Text>This is my first functional component</Text>
            <Text>Hello from {props.name}</Text>
        </Fragment>
    )
}

export default MyFirstFunctionalComponent;