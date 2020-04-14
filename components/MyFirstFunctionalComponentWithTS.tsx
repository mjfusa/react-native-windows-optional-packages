import React, { Fragment } from 'react';
import {
  Text
} from 'react-native';

interface Props {
    name: string
}


const MyFirstFunctionalComponent: React.FC<Props> = (props) => {
    
    return(
        <Fragment>
            <Text>This is my first functional component</Text>
            <Text>Hello from {props.name}</Text>
        </Fragment>
    )
}

export default MyFirstFunctionalComponent;